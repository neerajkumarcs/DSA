class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> m;
        // step -> store value with frequencies
        for(int i=0; i<n; i++){
            m[arr[i]]++; // note* map stores value with frequenciy
        }
        // step 2-> now check repeted frequencies
        unordered_set<int> s;
        for(auto ele: m){
            int freq=ele.second;// show frequency
            if(s.find(freq)!=s.end()) return false ;
            else s.insert(freq);
        }
        return true;
    }
};