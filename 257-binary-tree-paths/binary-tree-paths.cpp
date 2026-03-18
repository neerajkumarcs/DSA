class Solution {
public:
    void helper(TreeNode* root, string st, vector<string> &ans){
        if(root==nullptr) return ;
       string ch=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            st+=ch;// last node ko add kr rha hu kyoki append call mei ho rha, but last ke liye call nhi ho rha
            ans.push_back(st);
            return;
        }
       helper(root->left, st+ch+"->",ans);
       helper(root->right,st+ch+"->", ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
       helper(root, "", ans);
      return ans;  
    }
};