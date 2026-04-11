class Solution {
public:
    TreeNode* build(vector<int>&pre, int prelow, int prehigh, vector<int> & in, int inlow, int inhigh){
        if(prelow>prehigh) return NULL;
        TreeNode* root=new TreeNode(pre[prelow]);
        int i=inlow;
        while(i<=inhigh){
            if(in[i]==pre[prelow]) break;
            i++;
        }
        int leftcount=i-inlow;
        int rightcount=inhigh-i;
        root->left= build(pre,prelow+1,prelow+leftcount, in,inlow,i-1);
        root->right= build(pre,prelow+leftcount+1,prehigh, in, i+1, inhigh);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in= pre;
        sort(in.begin(), in.end());
        int n=in.size();
        return build(pre,0,n-1,in, 0,n-1);
    }
};