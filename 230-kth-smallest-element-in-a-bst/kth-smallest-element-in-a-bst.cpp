class Solution {
public:
    int inorder(TreeNode* root, int &order, int k) {
        if (root==NULL) return -1;

        int left = inorder(root->left, order, k);
        if (left != -1) return left;

        order++;
        if (order == k) return root->val;

        int right=inorder(root->right, order, k);
        if(right!=-1) return right;
         return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int order = 0;
        return inorder(root, order, k);
    }
};
