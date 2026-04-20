class Solution {
public:
    int reversenum(int x){
        int rev=0;
        while(x>0){
            rev=rev*10+(x%10);
            x=x/10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i=0; i<n ; i++){
          s.insert(nums[i]);
          s.insert(reversenum(nums[i]));
        }
        return s.size();
    }
};