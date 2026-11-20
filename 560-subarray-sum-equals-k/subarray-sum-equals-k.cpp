class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    vector<int> pre(nums.size());
    pre[0]=nums[0];
    for(int i=1;i<nums.size(); i++){
        pre[i]=pre[i-1]+nums[i];
    }   
    unordered_map<int,int> s;
    int count=0;
    for(int i=0;i<nums.size(); i++){
        if(pre[i]==k) count++;
            int rem=pre[i]-k;
            if(s.find(rem)!=s.end()) count+=s[rem];
        s[pre[i]]++;
    }
    return count;
    }
};