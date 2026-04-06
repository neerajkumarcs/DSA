class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(root==NULL) return new TreeNode(val);
        else if(root->val > val) { // go left if not NULL 
        if(root->left==nullptr) {
            TreeNode* temp=new TreeNode(val);
            root->left=temp;
        }
        else { // root->left not nullptr
            insertIntoBST(root->left, val);
        }

       } 
       else { // root->val < val : go right if not NULL
         if(root->right==nullptr) {
            root->right= new TreeNode(val);
         }
         else {
            insertIntoBST( root->right, val);
         }
       }
       return root;
    }
};