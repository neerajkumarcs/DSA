/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* root, int val){
        if(root==NULL) root=new TreeNode(val);
        else if(root->val>val){ // go to left
        if(root->left==NULL) root->left=new TreeNode(val);
        else insert(root->left, val); // go to left until null occure or move to right side 
        }
        else{ // root->val<val
        // attach to right
        if(root->right==nullptr) root->right=new TreeNode(val);
        else insert(root->right, val);// go to right until null occure or move to left side 
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      TreeNode* root=new TreeNode(preorder[0]);
      for(int i=1; i<preorder.size(); i++ ){
        insert(root, preorder[i]);
      } 
      return root; 
    }
};