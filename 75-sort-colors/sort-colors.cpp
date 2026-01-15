class Solution {
public:
    void sortColors(vector<int>& v) {
        // to pass solution
        int n=v.size();
        int i=0;
        int mid=0; 
        int j=n-1;
        while(mid<=j){
            if(v[mid]==2){
            int temp=v[mid];
            v[mid]=v[j];
            v[j]=temp;
            j--;
        }
        else if(v[mid]==0){
            int temp=v[mid];
            v[mid]=v[i];
            v[i]=temp;
            i++;
            mid++;
        }
        else mid++;
        }
    return ;
    }
};