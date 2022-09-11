#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (x)>(y) ? (x):(y)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}



int maxDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (MAX(left, right))+1;
}

