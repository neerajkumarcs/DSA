class Solution {
public:
    bool exist(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exist(root->left, target) || exist(root->right, target); // target root ke left ya fir right kahi na kahi to pakka hoga 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(exist(root->left,p) && exist(root->left,q))  return lowestCommonAncestor(root->left, p,q); // jab dono left mei ho
         if(exist(root->right,p) && exist(root->right,q)) return lowestCommonAncestor(root->right, p,q); // jab dono targets root ke right mei ho
         return root; 
    }
};