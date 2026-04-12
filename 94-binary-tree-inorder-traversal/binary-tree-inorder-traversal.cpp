class Solution {
public:
// inorder morris traversal 
    vector<int> inorderTraversal(TreeNode* root) {
    if(root==NULL) return {};
    vector<int> ans;
    TreeNode* curr=root;
    while(curr){
        if(curr->left){ // to find predecessor 
            TreeNode* pre=curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre=pre->right;
            }
        if(pre->right==NULL){ // when pre-> right reach at dead end (for linking )
            pre->right=curr;
            curr=curr->left;
        }    
        else{ // when pre->right== curr(for unlinking)
            pre->right=nullptr;
            ans.push_back(curr->val);
            curr=curr->right;
        }
        }
    else { // last case when current left==NULL
        ans.push_back(curr->val);
        curr=curr->right;
        }  
    }  
         return ans;
    }
};