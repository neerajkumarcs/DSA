class Solution {
public:
    void helper(vector<int>&nums, set<vector<int>>&s, vector<int>v,int idx){
        if(idx==nums.size()){
            s.insert(v);
            return ;
        }
        helper(nums,s,v, idx+1);
        v.push_back(nums[idx]);
        helper(nums, s, v, idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        vector<int> v;
        helper(nums,s,v,0);
        return vector<vector<int>>(s.begin(), s.end());
    }
};