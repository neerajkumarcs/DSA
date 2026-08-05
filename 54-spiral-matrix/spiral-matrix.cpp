class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int minr=0, maxr=m-1;
        int minc=0,maxc=n-1;
        int tn=m*n;
        int count=0;
        vector<int> v;
        while(minr<=maxr && minc<=maxc){
            // right
            for(int i=minc; i<=maxc && count<tn; i++){
                v.push_back(matrix[minr][i]);
                count++;
            }
            minr++;
            // down
            for(int i=minr; i<=maxr && count<tn; i++){
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            // left
            for(int i=maxc; i>=minc && count<tn; i--){
                v.push_back(matrix[maxr][i]);
                count++;
            }
            maxr--;
            //up 
            for(int i=maxr; i>=minr && count<tn; i--){
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;

        }
        return v;
    }
};