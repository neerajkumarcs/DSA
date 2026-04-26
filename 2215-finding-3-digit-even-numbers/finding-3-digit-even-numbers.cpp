class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto x: digits){
            m[x]++;
        }
        for(int i=100; i<=999; i+=2){
            int x=i;
            int a=x%10; x/=10;
            int b=x%10; x/=10;
            int c=x%10;
            if(m[a]>0){
                m[a]--;
                    if(m[b]>0){
                        m[b]--;
                            if(m[c]>0){
                                m[c]--;
                                ans.push_back(i);
                                m[c]++;
                            }
                            m[b]++;
                    }
                    m[a]++;
            }
    }
        return ans;
    }
};