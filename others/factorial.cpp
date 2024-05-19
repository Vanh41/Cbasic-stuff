#include <iostream>
#include <vector>
using namespace std;

void factorial(int n) {
    vector<int> v(200, 0);
    int c = 0, k = 0;
    v[0] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            v[j] = v[j] * i + c;
            c = v[j] / 10;
            v[j] %= 10;
        }

        while (c) {
            k++;
            v[k] = c % 10;
            c /= 10;
        }
    }

    for (int i = k; i >= 0; i--)
        cout << v[i];
}

int main() {
    int n = 100; // Change this value to compute factorial for a different number
    factorial(n);
    return 0;
}
