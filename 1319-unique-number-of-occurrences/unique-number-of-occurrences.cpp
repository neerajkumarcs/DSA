class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    int n=arr.size();
    unordered_set<int>s;
    unordered_map<int,int> m;
    for(int i=0; i<n;i++){
        m[arr[i]]++;
    }  
    for(auto x: m){
        int frq=x.second;
        if(s.find(frq)==s.end()){
            s.insert(frq);
        }
        else return false;
    } 
    return true;
    }
};