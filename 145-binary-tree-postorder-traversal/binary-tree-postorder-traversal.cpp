class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int>ans;
    s.push(root);
    while(!s.empty()){
        TreeNode* temp=s.top();
        s.pop();
        if(temp!=NULL){
            ans.push_back(temp->val);
            if(temp->left!=nullptr) s.push(temp->left);
            if(temp->right!=nullptr)s.push(temp->right);
        }
    }  
    reverse(ans.begin(),ans.end());
    return ans;
    
    }
};