class Solution {
public:
bool helper(TreeNode* root, int sum){
    if(root==NULL) return  false;
    if(root->left==nullptr && root->right==nullptr){
        if(root->val==sum) return true;
    }
    return helper(root->left, sum-root->val)|| helper(root->right, sum-root->val);
    return false;
    

}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return helper(root, targetSum);
    }
};