class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        int idx=i;
        while(!s.empty() && s.top()<=nums[idx]) s.pop();
        ans[idx]=s.empty()?-1:s.top();
        s.push(nums[idx]);
    }  
    for(int i=n-1; i>=0; i--){
        int idx=i;
        while(!s.empty() && s.top()<=nums[idx]) s.pop();
        ans[idx]=s.empty()?-1:s.top();
        s.push(nums[idx]);
    }  
    return ans;
    }
};