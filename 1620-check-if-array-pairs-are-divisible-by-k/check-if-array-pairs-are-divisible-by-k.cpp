class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // hint -> create a modulas k array 
        int n=arr.size();
        for(int i=0; i<n ;i++){
            arr[i] = ((arr[i] % k) + k) % k;
        }
        unordered_map<int, int >m;
        for(int i=0; i< n; i++){
            m[arr[i]]++;
        }
        if(m.find(0)!=m.end()){
            if(m[0]%2!=0) return false;
            m.erase(0);
        }
        for(auto x: m){
            int val=x.first;
            int rem=k-val;
            if(2 * val == k){
            if(m[val] % 2 != 0) return false;
            continue;
        }
            if(m.find(rem)==m.end()) return false;
            if(m[val]!=m[rem]) return false;
        }
        return true;
    }
};