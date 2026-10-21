class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
    // iterative method
    stack<TreeNode*> s;
    s.push(root);
    vector<int> ans;
    while(!s.empty()){
        TreeNode* temp=s.top();
        s.pop();
        if(temp!=NULL)ans.push_back(temp->val);
        if(temp!=NULL && temp->right!=NULL)s.push(temp->right);
        if(temp!=nullptr && temp->left!=NULL) s.push(temp->left);
    }
    return ans;
    }
};