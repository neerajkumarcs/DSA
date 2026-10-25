class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* pre=root->right;
        while(pre->left){
            pre=pre->left;
        }
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return nullptr;
    if(root->val==key){
        // case 1 ->for leaf node
        if(root->left==NULL && root->right==NULL) return NULL;

        // case 2-> only one child
        if(root->left==NULL || root->right==NULL){
            if(root->left==NULL) return root->right;
            else return root->left;
        } 
        // case 3-> both childrens are not null
        if(root->left && root->right){
            // replace with inorder predececor 
            TreeNode* pred=iop(root);    
            root->val=pred->val;
            root->left=deleteNode(root->left, pred->val);
        }
    }
    else if(root->val >key ) root->left=deleteNode(root->left, key);
    else root->right=deleteNode(root->right, key);
    return root;

    }
};