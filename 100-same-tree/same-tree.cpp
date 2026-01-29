class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL ) return true;
        if(p==NULL || q==NULL ) return false;
        if(p->val!= q->val) return false;
        bool lstans=isSameTree(p->left, q->left);
        if(lstans==false) return false;
        bool rstans= isSameTree(p->right, q->right);
        if(rstans==false) return false;

       return true;
    }
};