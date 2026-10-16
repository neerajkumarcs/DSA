class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr ||(root->left==NULL && root->right==NULL))
            return true;
        int l,r;    
        if(root->left!=NULL) l=root->left->val;
        if(root->right!=NULL) r=root->right->val;
        if(l!=r) return false;
        return isMirror(root->left, root->right);
    }
};