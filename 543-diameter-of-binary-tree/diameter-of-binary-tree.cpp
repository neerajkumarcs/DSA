class Solution {
public:
int maxdia=0;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int dia=levels(root->left)+levels(root->right); // har root ki maximum dia find kr rha rha
        maxdia=max(maxdia, dia);// pichhle dia se compare krne maximum ko store kr rha 
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdia;
    }
};