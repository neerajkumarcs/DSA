class Solution {
public:
    void sortColors(vector<int>& nums) {
     int n=nums.size();
     int right=0;// pointer 1
     for(int i=0; i<n; i++){
        if(nums[i]==0){
            swap(nums[right],nums[i]);
            right++;
        }
     }   
     int last=n-1; // 2nd pointer
     for(int i=n-1; i>=right; i--){
        if(nums[i]==2){
            swap(nums[i],nums[last]);
            last--;
        }
     }
    }
};