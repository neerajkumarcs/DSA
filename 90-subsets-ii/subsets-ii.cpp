class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Generate all 2^n subsets
        for(int k = 0; k < (1 << n); k++) {
            vector<int> t;

            for(int i = 0; i < n; i++) {
                if(k & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }

            v.push_back(t);
        }

        // Remove duplicate subsets
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        return v;
    }
};