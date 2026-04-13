class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*> &ans){
        if(root == NULL) return;

        ans.push_back(root);        // store node accoring to preoder
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void flatten(TreeNode* root) {
        if(root == NULL) return;

        vector<TreeNode*> ans;  // vector node type
        preorder(root, ans);

        for(int i = 0; i < ans.size() - 1; i++){
            ans[i]->right = ans[i + 1];
            ans[i]->left = NULL;
        }

        // // last node fix
        // if(ans.size() > 0){
        //     ans.back()->left = NULL;
        //     ans.back()->right = NULL;
        //}
    }
};