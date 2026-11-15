class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        for(int i=0; i<n; i++){
            int t=target-nums[i];
            if(m.find(t)!=m.end() && i!=m[t]){
                return {i, m[t]};
            }
        }
        return { };
    }
};