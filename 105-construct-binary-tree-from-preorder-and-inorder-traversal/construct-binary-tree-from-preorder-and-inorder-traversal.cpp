/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* build(vector<int>& preorder, int prel, int preh, vector<int>& inorder, int inl, int inh){
    if(prel>preh) return NULL;
    TreeNode* root=new TreeNode(preorder[prel]);
    if(prel==preh) return root;
    int i=inl;
    while(i<=inh){
        if(inorder[i]==preorder[prel]) break;
        i++;
    }
    int leftcount=i-inl;
    int rightcount=inh-i;
    root->left=build(preorder,prel+1,prel+leftcount,inorder,inl,i-1);
    root->right=build(preorder,prel+leftcount+1,preh,inorder,i+1,inh);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};