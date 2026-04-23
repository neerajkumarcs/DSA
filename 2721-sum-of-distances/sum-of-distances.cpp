class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int m = pos.size();

            // prefix sum
            vector<long long> prefix(m);
            prefix[0] = pos[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            // calculate answer
            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                if (i > 0)
                    left = (long long)i * pos[i] - prefix[i - 1];

                if (i < m - 1)
                    right = (prefix[m - 1] - prefix[i]) - (long long)(m - i - 1) * pos[i];

                ans[pos[i]] = left + right;
            }
        }

        return ans;
    }
};