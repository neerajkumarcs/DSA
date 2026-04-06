class Solution {
public:
    void inorder(TreeNode* root, int &sum){
        if(root==nullptr) return ;
        inorder(root->right,sum);
        sum+=root->val;
        root->val=sum;
        inorder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr) return NULL;
        int sum=0;
        inorder(root,sum);
        return root;
    }
};