class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // step 1-> make first row defaut 1
        for(int i=0; i<m; i++){
            if(grid[i][0]==0){
                for(int j=0; j<n; j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
            
        }
        // step 2-> check where noz or noo 
        for(int i=0; i<n; i++){
            int noz=0;
            int noo=0;
            for(int j=0; j<m; j++){
                if(grid[j][i]==0) noz++;
                else noo++;
            }
            if(noz>noo){
                for(int j=0; j<m; j++){
                     grid[j][i]=1-grid[j][i];
                }
            }
        }
            // step 3-> now add according to binary nummber
            int sum=0;
            for(int i=m-1; i>=0; i--){
                int x=1;
                for(int j=n-1; j>=0; j--){
                    sum+=grid[i][j]*(x);
                    x=x*2;
                }
            }

            return sum;
    }
};