class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();        // ✅ current level size
            vector<int> level;          // ✅ store this level

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);   // ✅ same level

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(level);   // ✅ push full level
        }

        return ans;
    }
};