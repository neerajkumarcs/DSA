class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> ans;
     stack<TreeNode*> st;
     if(root!=NULL)st.push(root);
     while(st.size()>0){
        TreeNode* temp=st.top();
        ans.push_back(temp->val);
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
     }
     return ans;
    }
};