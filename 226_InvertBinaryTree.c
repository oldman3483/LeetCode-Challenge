struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}; 


struct TreeNode* invertTree(struct TreeNode* root){

    if((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
        return root; 
    
    struct TreeNode *tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
    
}