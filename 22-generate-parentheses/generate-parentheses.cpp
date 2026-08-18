class Solution {
public:
    void para(vector<string>&ans,string st,int n,int o, int c){
        if(o==n && c==n) {
            ans.push_back(st);
            return;
        }
        if(o<n) para(ans,st+'(',n,o+1,c);
        if(c<o) para(ans,st+')',n, o, c+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        para(ans,"",n,0,0);
        return ans;
    }
};