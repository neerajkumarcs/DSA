class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> yes(n+1);
        vector<int> no(n+1);
        // to calculate No
        no[0]=0;
        int Ncount=0;
        for(int i=1; i<=n; i++){
            if(customers[i-1]=='N') Ncount++;
            no[i]=Ncount;
        }
        yes[n]=0;
        int Ycount=0; 
        for(int i=n-1;i>=0; i--){
            if(customers[i]=='Y') Ycount++;
            yes[i]=Ycount;
        }

        // pnanalty array
        for(int i=0; i<=n; i++){
            no[i]+=yes[i];
        }
        int mx=no[0];
        int idx=0;
        for(int i=0; i<=n; i++){
            if(no[i]<mx) {
                mx=no[i];
                idx=i;
            }
        }
    return idx;

    }
};