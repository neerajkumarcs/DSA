class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(int ele : nums) {
            m[ele]++;
        }

        int ans = 0;

        for(int ele : nums) {

            int need = k - ele;

            if(m[ele] > 0 && m[need] > 0) {

                // same number case
                if(ele == need && m[ele] < 2)
                    continue;

                ans++;

                m[ele]--;
                m[need]--;
            }
        }

        return ans;
    }
};