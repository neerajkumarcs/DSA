class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotidx = -1;

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivotidx = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if (pivotidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + pivotidx + 1, nums.end());

        // step 4: find just greater than pivot
        int j=-1;
        for(int i=pivotidx+1; i<n; i++){
            if(nums[i]>nums[pivotidx]){
                j=i;
                break;
            }
        }
        swap(nums[pivotidx],nums[j]);
        return ;  

    }
};