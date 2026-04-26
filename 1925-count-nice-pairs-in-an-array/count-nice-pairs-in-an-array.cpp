class Solution {
public:
     int rev(int n){
        int r=0; 
        while(n>0){
            int digit=n%10;
            r=r*10+digit;
            n/=10;
        }
        return r;
     }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> m;
        long long count=0;
        for(int i=0; i<n; i++){
            int val=(nums[i]-rev(nums[i]));
           if(m.find(val)!=m.end()) {
            //count=count%1000000007;
            count+=m[val];
           }
           m[val]++;
        }
    return count%1000000007; // Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7. 
    }
};