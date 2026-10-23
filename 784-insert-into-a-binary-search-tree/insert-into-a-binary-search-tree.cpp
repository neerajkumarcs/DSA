class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
    if(root->val > val){
        if(root->left==NULL) {
            root->left= new TreeNode(val);
        }
      insertIntoBST(root->left,val);
    }
    if(root->val < val){
        if(root->right==nullptr) {
            root->right=new TreeNode(val);
        }
         insertIntoBST(root->right,val);
    }   
    return root;
    }
};