class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
       unordered_map<string, vector<string>> mp;
       int n=strs.size();
       for(int i=0; i<n; i++){
        string st=strs[i];
        sort(st.begin(), st.end());
        if(mp.find(st)==mp.end()){
            vector<string> v;
            v.push_back(strs[i]);
            mp[st]=v;
        }
        else {
        mp[st].push_back(strs[i]); 
        }
       }
    for(auto x:mp){
        vector<string> v=x.second;
        ans.push_back(v);
    }
    return ans;
    }
};