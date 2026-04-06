class Solution {
public:
    void inorder(TreeNode* root, int &sum){ // inorder traversal from right to left (means reverse order)
        if(root==nullptr) return ;
        inorder(root->right,sum);
        sum+=root->val; // previous root ka values ko store kr rha hai 
        root->val=sum; // root ki value ka modification ho rha hai 
        inorder(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==nullptr) return NULL;
        int sum=0;
        inorder(root,sum);
        return root;
    }
};