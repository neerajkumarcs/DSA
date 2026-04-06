class Solution {
public:
void inorder(TreeNode* root, vector<int>&ans){
    if(root==nullptr) return ;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right,ans);

}
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        bool flag =true;
        for(int i=1; i<ans.size() ; i++){
            if(ans[i]<=ans[i-1]){
                flag =false;
                break;
            }
        }
        if(flag) return true;
        else return false;
    }
};