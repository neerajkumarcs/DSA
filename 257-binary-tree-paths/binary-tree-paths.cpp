class Solution {
public:
 void helper(TreeNode* root, string s, vector<string> &ans){
    if(root==NULL) return ;
    string ch=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
        s+=ch;
        ans.push_back(s);
        return ;
    }
    helper(root->left, s+ch+"->", ans);
    helper(root->right, s+ch+"->", ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
        
    }
};