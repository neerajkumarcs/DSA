class Solution {
public:
    TreeNode* inop(TreeNode* root){
        // step 1:- go right once 
        // step 2:- keep going left until dead/ lead occure
        TreeNode* pre=root->left;
        while(pre->right!=NULL){
            pre=pre->right;
        }
        return pre;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return nullptr; // in case of null tree
    if(root->val==key ){

    // case 1-> No child node (lead node)
    if(root->left==nullptr && root->right==nullptr) return NULL;

    // case 2-> one child node 
    if(root->left==NULL || root->right==NULL){
        if(root->right==NULL) return root->left;
        else return root->right;
    }

    // 2 or more child node 
    if(root->left && root->right){
        // step 1:- find inorder  predecessor or succesor of key node 
        // step 2:- replace key  node with its prede or succe
        TreeNode* pre=inop(root);
        root->val=pre->val;
        // Node* predecessor alwayays at left of key node
        root->left=deleteNode(root->left, pre->val);
    }
    }   
    else if(root->val>key) { // go to left
    root->left=deleteNode(root->left, key);
    }
    else root->right=deleteNode(root->right, key); // in case root->val< key
    return root;
    }
};