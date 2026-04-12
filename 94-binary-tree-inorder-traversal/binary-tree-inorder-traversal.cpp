class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr=root;
    while(curr){
        if(curr->left){
            TreeNode* pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
        if(pre->right==NULL){ // when pre-> right reach at dead end 
            pre->right=curr;
            curr=curr->left;
        }    
        else{ // when pre->right== curr
            pre->right=nullptr;
            ans.push_back(curr->val);
            curr=curr->right;
        }
        }
    else {
        ans.push_back(curr->val);
        curr=curr->right;
        }  
    }  
         return ans;
    }
};