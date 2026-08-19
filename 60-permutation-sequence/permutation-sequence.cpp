class Solution {
public:
string helper(string org, int k, string ans){
    int n=org.length();
    if(n==0) return ans;
    int fact=1;
    for(int i=2; i<=n-1; i++) fact*=i;
    int idx=k/fact;
    if(k%fact==0) idx--;
    char ch=org[idx];
    string left=org.substr(0,idx);
    string right= org.substr(idx+1);
    int q;
    if(k%fact==0) q=fact;
    else  q=k%fact; 
    return helper(left+right,q,ans+ch);
}
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1; i<=n; i++){
            str+=to_string(i);
        }
        string ans="";
        return helper(str,k,"");
    }
};