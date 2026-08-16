class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>>&fans, vector<int> ans, int idx){
        int n=nums.size();
        if(idx==nums.size()){
            fans.push_back(ans);
            return;
        }
        
        helper(nums,fans,ans,idx+1);
        ans.push_back(nums[idx]);
        helper(nums, fans, ans , idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> fans;
       vector<int> ans;
       helper(nums, fans, ans, 0);
       return fans;

    }
};