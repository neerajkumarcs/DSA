class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int count=0;
        int ans=count;
        for(int i=0;i<n;i++){
            if(i<n-1 && s[i]==s[i+1]){
                count++;
                ans=max(ans, count);
            }
            else count=0;
        }
        return ans+1;
    }
};