class Solution {
public:
int maxdia=0;
int levels( TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(levels(root->left), levels(root->right));
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia= levels(root->right)+levels(root->left);
        maxdia=max(dia, maxdia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};