class Solution {
public: 
    void nthlvl(TreeNode* root, int cn, int n, vector<int> &v){
        if(root==NULL) return ;
        if(cn==n){
            v.push_back(root->val);
            return;
        }
        nthlvl(root->left,cn+1, n, v);
        nthlvl(root->right,cn+1, n, v);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0; 
        return 1+max(levels(root->left), levels(root->right));
    }
    void lorder(TreeNode* root, vector<vector<int>> &ans){
        if(root==NULL) return ;
        int n=levels(root);
        for(int i=1; i<=n ;i++){
            vector<int> v;
            nthlvl(root,1,i,v);// where i is current lvl, i is tree lvl, v is vector where to store;
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lorder(root,ans);
        return ans;
    }
};