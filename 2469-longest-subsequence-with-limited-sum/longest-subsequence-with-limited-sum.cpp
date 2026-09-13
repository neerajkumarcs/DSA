class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        // to create prefix
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0; i<m; i++){
            int len=0;
            int j=0 ;
            while(j<n && nums[j]<=queries[i]){
                len++;
                j++;
            }
            queries[i]=len;
        }
        return queries;
    }       
};