class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return strs[0];
        sort(strs.begin(),strs.end());
        int i;
        for( i=0; i<min(strs[0].size(),strs[n-1].size()); i++){
            if(strs[0][i]!=strs[n-1][i]) break;
        }
        return strs[0].substr(0,i);
    }
};