#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ORDERS 100000
#define HASH_SIZE 100003  // A large prime number for better hash distribution

typedef struct Order {
    char customerID[11];
    char productID[11];
    int price;
    char shopID[11];
    char timePoint[9];
} Order;

typedef struct Node {
    char key[22];  // For customer-shop and shop hash tables
    int value;
    struct Node* next;
} Node;

Order orders[MAX_ORDERS];
int orderCount = 0;

Node* shopRevenueHash[HASH_SIZE];
Node* customerShopRevenueHash[HASH_SIZE];

int totalRevenue = 0;

// Hash function
unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % HASH_SIZE;
}

// Insert into hash table
void insert(Node* hashTable[], const char* key, int value) {
    unsigned int index = hash(key);
    Node* node = hashTable[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->value += value;
            return;
        }
        node = node->next;
    }
    node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->next = hashTable[index];
    hashTable[index] = node;
}

// Get value from hash table
int get(Node* hashTable[], const char* key) {
    unsigned int index = hash(key);
    Node* node = hashTable[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

// Helper function to convert time string to total seconds for easy comparison
int convertTimeToSeconds(const char* timePoint) {
    int hours, minutes, seconds;
    sscanf(timePoint, "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

// Function to handle each query and print the result
void processQuery(char* query) {
    if (strcmp(query, "?total_number_orders") == 0) {
        printf("%d\n", orderCount);
    } else if (strcmp(query, "?total_revenue") == 0) {
        printf("%d\n", totalRevenue);
    } else if (strncmp(query, "?revenue_of_shop", 16) == 0) {
        char shopID[11];
        sscanf(query, "?revenue_of_shop %s", shopID);
        printf("%d\n", get(shopRevenueHash, shopID));
    } else if (strncmp(query, "?total_consume_of_customer_shop", 31) == 0) {
        char customerID[11], shopID[11], key[22];
        sscanf(query, "?total_consume_of_customer_shop %s %s", customerID, shopID);
        snprintf(key, sizeof(key), "%s|%s", customerID, shopID);
        printf("%d\n", get(customerShopRevenueHash, key));
    } else if (strncmp(query, "?total_revenue_in_period", 24) == 0) {
        char fromTime[9], toTime[9];
        sscanf(query, "?total_revenue_in_period %s %s", fromTime, toTime);
        int fromSeconds = convertTimeToSeconds(fromTime);
        int toSeconds = convertTimeToSeconds(toTime);
        int periodRevenue = 0;
        for (int i = 0; i < orderCount; i++) {
            int orderSeconds = convertTimeToSeconds(orders[i].timePoint);
            if (orderSeconds >= fromSeconds && orderSeconds <= toSeconds) {
                periodRevenue += orders[i].price;
            }
        }
        printf("%d\n", periodRevenue);
    }
}

int main() {
    char line[256];

    // Read orders
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '#') break;
        sscanf(line, "%s %s %d %s %s", orders[orderCount].customerID, orders[orderCount].productID,
               &orders[orderCount].price, orders[orderCount].shopID, orders[orderCount].timePoint);
        
        // Update total revenue
        totalRevenue += orders[orderCount].price;
        
        // Update shop revenue hash table
        insert(shopRevenueHash, orders[orderCount].shopID, orders[orderCount].price);
        
        // Update customer-shop revenue hash table
        char key[22];
        snprintf(key, sizeof(key), "%s|%s", orders[orderCount].customerID, orders[orderCount].shopID);
        insert(customerShopRevenueHash, key, orders[orderCount].price);
        
        orderCount++;
    }

    // Read and process queries
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '#') break;
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        processQuery(line);
    }

    // Free memory in hash tables
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* node = shopRevenueHash[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
        node = customerShopRevenueHash[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return 0;
}
