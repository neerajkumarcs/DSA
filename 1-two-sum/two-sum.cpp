class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];

            // check if required number already seen
            if(mp.find(required) != mp.end()) {
                return {mp[required], i};
            }

            // store current element
            mp[nums[i]] = i;
        }

        return {}; // just for safety
    }
};