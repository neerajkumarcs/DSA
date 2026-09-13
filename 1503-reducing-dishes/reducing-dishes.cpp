class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // approach 
        // 1-> sorting
        // 2-> all +ve must be taken
        //2-> create suffix sum 
        // 3-> take from that index where all suffix is in +ve
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        if(satisfaction[n-1]<0) return 0;
        vector<int> suff(n);
        int idx=0;
        suff[n-1]=satisfaction[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i]+=suff[i+1]+satisfaction[i];
            if(suff[i]<0) {
                idx=i+1;
                break;
            }
        }
        int sum=0;
        int h=1;
        for(int i=idx; i<n; i++){
            sum+=satisfaction[i]*h;
            h++;
        }
        return sum;

    }
};