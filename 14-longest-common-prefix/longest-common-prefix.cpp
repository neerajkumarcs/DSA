class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int n=strs.size();
    //if(n==1) return strs[0];
    sort(strs.begin(),strs.end());
    string f=strs[0];
    string l=strs[n-1];
    int minsize=min(f.size(),l.size()); // fi
    string s="";
    for(int i=0; i<minsize; i++){
        if(f[i]==l[i]) s+=f[i];
        else return s;
    }
    return s;// in case all strings are same

    }
};