/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL ) return result;
        stack<TreeNode*> currlvl;
        stack<TreeNode*> nxtlvl;
        vector<int> lvl;// use to store every level
        currlvl.push(root);
        bool lefttoright=true;
        while(!currlvl.empty()){
            TreeNode* temp=currlvl.top();
            lvl.push_back(temp->val);
            currlvl.pop();
            if(temp){
                if(lefttoright){
                    if(temp->left) nxtlvl.push(temp->left);
                    if(temp->right) nxtlvl.push(temp->right);
                }
                else{
                    if(temp->right) nxtlvl.push(temp->right);
                    if(temp->left) nxtlvl.push(temp->left);
                }
            }
                // after level
                if(currlvl.empty()){
                    result.push_back(lvl);
                    lvl.clear(); // for resting the 1d vector
                    lefttoright=!lefttoright;
                    swap(currlvl,nxtlvl);
            
                }
        }
        return result;
    }
};