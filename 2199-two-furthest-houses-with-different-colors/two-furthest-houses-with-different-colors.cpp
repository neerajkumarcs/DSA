class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0, j=n-1;
        int a, b;
        while(i<j){
            if(colors[i]!=colors[j]) {
                a=j-i; break;
            }
            j--;
        }
        i=0, j=n-1;
         while(i<j){
            if(colors[j]!=colors[i]){
                 b=j-i; break;
            }
           i++;
        }
        return max(a,b);
    }
};