class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int tar) {
       if(root==NULL) return NULL;
       else if(root->val==tar) return root;
       else if(root->val>tar) return searchBST(root->left, tar);
       else return searchBST( root->right, tar);
        return NULL; 
    }
};