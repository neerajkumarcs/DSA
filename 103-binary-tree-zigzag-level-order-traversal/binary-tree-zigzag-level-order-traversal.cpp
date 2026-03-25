class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        stack<TreeNode*> currlvl;
        stack<TreeNode*> nxtlvl;

        bool leftToRight = true;
        currlvl.push(root);

        vector<int> level;

        while(!currlvl.empty()){
            TreeNode* temp = currlvl.top();
            currlvl.pop();

            if(temp){
                level.push_back(temp->val);

                if(leftToRight){
                    if(temp->left) nxtlvl.push(temp->left);
                    if(temp->right) nxtlvl.push(temp->right);
                } else {
                    if(temp->right) nxtlvl.push(temp->right);
                    if(temp->left) nxtlvl.push(temp->left);
                }
            }

            // end of level
            if(currlvl.empty()){
                result.push_back(level);   
                level.clear();             // to become again emplty

                leftToRight = !leftToRight; // flip direction
                swap(currlvl, nxtlvl);
            }
        }

        return result;
    }
};