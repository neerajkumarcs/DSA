class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> m;
    vector<int> ans;
    for(int ele: arr1){
        m[ele]++;
    }
    for(int ele: arr2){
        while(m[ele]>0){
            ans.push_back(ele);
            m[ele]--;
        }
        m.erase(ele);
    }
    vector<int> temp;
    for(auto x: m){
        while(x.second > 0){
            temp.push_back(x.first);
            x.second--;
        }
    }
    sort(temp.begin(), temp.end());
    for(auto x: temp){
        ans.push_back(x);
    }
    return ans;
    }
};