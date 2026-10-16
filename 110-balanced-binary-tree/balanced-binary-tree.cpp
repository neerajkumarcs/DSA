class Solution {
public:
    int helper(TreeNode* root, bool &ans){
        if(root==NULL) return 0;
        int lh=helper(root->left,ans);
        int rh=helper(root->right,ans);
        if(abs(lh-rh)>1){
            ans=false;
            return 0;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
    bool ans=true;
    helper(root, ans);
    return ans;  
    }
};