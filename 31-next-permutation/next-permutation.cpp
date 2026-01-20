class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotidx = -1;

        // 1. Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivotidx = i;
                break;
            }
        }

        // 2. If no pivot → reverse whole array
        if (pivotidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3. sorting after pivotidx
        reverse(nums.begin() + pivotidx + 1, nums.end());
        // 4. Swap with just larger element (right to left)
        int i = pivotidx;
        while (i!=n) {
            if (nums[i] > nums[pivotidx]) {
                swap(nums[i], nums[pivotidx]);
                break;
            }
            i++;
        }
     return ;
        
    }
};
