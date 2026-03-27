class Solution {
public:
void helper(TreeNode* root,vector<vector<int>>& result, vector<int>v, int target ){
    if(root==nullptr) return;
    if(root->left==NULL && root->right==NULL){
        if(root->val==target) { // ye base case hai jo check kr rha ki last mei jo value hai wo dono brabar ho and - mei zero ayega 
            v.push_back(root->val);
            result.push_back(v);
        }
        return;
    }
    v.push_back(root->val);
    helper(root->left,result, v,target-(root->val));
    helper(root->right,result, v,target-(root->val));
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> result;
       vector<int> v;
       helper(root, result, v, targetSum);
        return result;
    }
};