class Solution {
public:
    int reverse(int n){
        int temp=0;
        while(n>0){
            temp=temp*10;
            temp+=n%10;
            n/=10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) {
    int n=nums.size();
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(nums[i]);
        int rev=reverse(nums[i]);
        s.insert(rev);
    }  
    return s.size();
    }
};