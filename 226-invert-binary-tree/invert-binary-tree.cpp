class Solution {
public:
    void helper(TreeNode* root){
        if(root==nullptr) return ;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        helper(root->left); // left root ko call ho rha jo pahle swap ho chuka hai 
        helper(root->right);// right root ko call ho rha jo pahle swap ho chuka hai 
    }
    TreeNode* invertTree(TreeNode* root) {
    helper(root);
    return root;    
    }
};