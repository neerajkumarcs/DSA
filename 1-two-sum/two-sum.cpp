class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        //int i=0; 
        //int j=n-1; 
        // for(int i=0; i<n;i++){ // O(n)
        //     for(int j=n-1; j>i; j--)
        //     if(nums[i]+nums[j]==target){
        //         cout<<"("<<i<<","<<j<<")"<<endl;
        //         return {i,j};

                
        //     }
        // }
        // return {};
        vector<pair<int, int>>v;
        for(int i=0; i<n ; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        int i=0,j=n-1;
        while(i<j){
            if(v[i].first+v[j].first==target) return{v[i].second,v[j].second};
            else if(v[i].first+v[j].first<target) i++;
            else j--;
        }

        return { };
    }
};