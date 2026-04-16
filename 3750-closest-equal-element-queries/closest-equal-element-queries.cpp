class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Store indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int q : queries) {
            int val = nums[q];
            vector<int>& v = mp[val];
            
            // Only one occurrence
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Binary search
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int res = INT_MAX;
            
            // Check previous
            int prev = (idx - 1 + v.size()) % v.size();
            int dist1 = abs(q - v[prev]);
            res = min(res, min(dist1, n - dist1));
            
            // Check next
            int next = (idx + 1) % v.size();
            int dist2 = abs(q - v[next]);
            res = min(res, min(dist2, n - dist2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};