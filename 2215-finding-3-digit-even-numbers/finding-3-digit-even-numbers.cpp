class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto x: digits){ // step 1-> inseting all values in map with their frequencies
            m[x]++;
        }
        for(int i=100; i<=999; i+=2){ // step 2-> hint max number of three digit from 100 to 999
            int x=i;
            int a=x%10; x/=10; 
            int b=x%10; x/=10;
            int c=x%10;
            if(m[a]>0){ // check if first digit find in map
                m[a]--; // decrease frequency
                    if(m[b]>0){ // check if second digit find in map 
                        m[b]--;// decrease frequency
                            if(m[c]>0){ // exist 3rd digit 
                                m[c]--;// decrease frequency
                                ans.push_back(i);
                                m[c]++; // restore 
                            }
                            m[b]++; // restore 
                    }
                    m[a]++; // restore
            }
    }
        return ans;
    }
};