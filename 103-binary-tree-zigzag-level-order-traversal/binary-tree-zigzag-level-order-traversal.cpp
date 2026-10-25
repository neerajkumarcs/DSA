
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int l = 1;

        while(!q.empty()) {
            int size = q.size();
            vector<int> v;

            for(int i = 1; i <= size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp->val);

                // Always push children from left to right
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            // Reverse alternate levels
            if(l % 2 == 0) {
                reverse(v.begin(), v.end());
            }

            ans.push_back(v);
            l++;
        }

        return ans;
    }
};
