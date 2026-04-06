class Solution {
public:
    TreeNode* helper(vector<int>& nums, int low, int hi){
        if(low>hi) return NULL;
        int mid=low+(hi-low)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,low, mid-1);
        root->right=helper(nums, mid+1, hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, 0, n-1);
    }
};