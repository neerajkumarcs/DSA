class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void nthlvl(TreeNode* root, int curr, int level,vector<int>&ans){
        if(root==NULL) return ;
        if(curr==level){
            ans[curr]=root->val;
            return;
        }
        nthlvl(root->left,curr+1,level,ans);
        nthlvl(root->right,curr+1,level,ans);
    }
    void lOrder(TreeNode* root,vector<int>& ans){
    int n=ans.size();  
    for(int i=0; i<n ;i++){
        nthlvl(root,0,i,ans);
    }  
    }
    vector<int> rightSideView(TreeNode* root) {
    int levels=level(root);   
    vector<int> ans(levels,0);
    lOrder(root,ans);
    return ans;
    }
};