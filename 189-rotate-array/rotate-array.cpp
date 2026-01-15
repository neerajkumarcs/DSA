class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;

        vector<int> temp;

        // last k elements
        for(int i = n - k; i < n; i++){
            temp.push_back(nums[i]);
        }

        // shift remaining elements
        for(int i = n - k - 1; i >= 0; i--){
            nums[i + k] = nums[i];
        }

        // copy back
        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};
