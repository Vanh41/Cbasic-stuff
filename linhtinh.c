#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int main(){
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum;
int count=0;
int ans=0;
void traverse(struct TreeNode* root,int targetSum){
    if (root==NULL) return;
    sum+=root->val;
    printf("%d %d\n",sum,ans);
    if (sum==targetSum) {
        ans++;
        printf("ok\n");
    }
    traverse(root->left,targetSum);
    traverse(root->right,targetSum);
    sum-=root->val;
    return;
}

void checkeachnode(struct TreeNode* root, int targetSum){
    sum=0;
    if (root==NULL) return;
    traverse(root,targetSum);
    checkeachnode(root->left,targetSum);
    checkeachnode(root->right,targetSum);
    return;
}

int pathSum(struct TreeNode* root, int targetSum) {
    int ans=0;
    checkeachnode(root,targetSum);
    printf("%d\n",ans);
    return ans;
}
}
