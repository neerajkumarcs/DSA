class Solution {
public:
    TreeNode* helper(vector<TreeNode*> &v, int low, int high){
        if(low>high) return NULL;
        int mid=low+(high-low)/2;
        TreeNode* root=v[mid];
        root->left=helper(v, low, mid-1);
        root->right= helper(v, mid+1, high);
        return root;
    }
     void inorder(TreeNode* root, vector<TreeNode*> &v){
        if(root==NULL) return ;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
     }
    TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> v;

     inorder(root, v);

    return helper(v,0, v.size()-1); 
    }
};