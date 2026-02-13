class Solution {
public:
int secmin(TreeNode* root,int minval){
    if(root==NULL) return -1;
    if(root->val>minval){
        return root->val;
    }
    long left=secmin(root->left, minval);
    long right=secmin(root->right, minval);
    if(left==-1) return right;
    if(right==-1) return left;
    return min(left, right);
}
    int findSecondMinimumValue(TreeNode* root) {
       int minval=root->val;
       long ans=secmin(root,minval);
       return ans;
    }
};