class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int n=arr1.size();
    vector<int> ans(n);
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr1[i]]++; // storing values with their freqencies
    }
    int a=0;
    for(int i=0; i<arr2.size(); i++){
        if(m.find(arr2[i])!=m.end()){
         int fre=m[arr2[i]];
         while(fre>0){
            arr1[a]=arr2[i];
            fre--;
            a++;
         }
         m.erase(arr2[i]);
        }
    }

    // remaining elements 
    vector<int> temp;
    for(auto x: m){
        int frq=x.second;
        while(frq>0){
            temp.push_back(x.first);
            frq--;
        }
    }
    // sorting remaing elements;
    sort(temp.begin(),temp.end());
    for(int i=0; i<temp.size();i++){
        arr1[a]=temp[i];
        a++;
    }
    return arr1;
    }
};