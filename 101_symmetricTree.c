struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL)
        return true;
    else{
        return isSymmetricTree(root->left, root->right);
    }
}

int isSymmetricTree(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL || right ==NULL)
    {
        if (left == right)
            return true;
        else
            return false;
    }
    if (right->val != left->val)
        return false;
    else
    {
        return isSymmetricTree(left->left, right->right) && isSymmetricTree(left->right, right->left);
    }
}