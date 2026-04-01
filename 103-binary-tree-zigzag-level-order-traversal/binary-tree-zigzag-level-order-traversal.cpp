class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool lefttoright = true;

        while(q.size() > 0){
            vector<int> level;
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(!lefttoright){
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            lefttoright = !lefttoright;
        }

        return ans;
    }
};