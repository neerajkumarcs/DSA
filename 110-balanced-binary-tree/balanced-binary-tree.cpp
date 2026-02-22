class Solution {
public:
bool ans=true;
int helper(TreeNode* root){
    if(root==NULL) return 0;
    int lh=helper(root->left);
    int rh=helper(root->right);
    if(abs(lh-rh)>1) ans =false;
    return max(lh,rh)+1;
}
    bool isBalanced(TreeNode* root) {
        helper(root);
        return ans;
    }
};