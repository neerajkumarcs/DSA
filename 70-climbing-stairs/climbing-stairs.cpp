class Solution {
public:
    int climbStairs(int n) {
        // // suppose stairs is 4 
        // // ways 1,2
        // if(n==1) return 1;
        // if(n==2) return 2;
        // return climbStairs(n-1)+climbStairs(n-2);-> shows time limit exceed 
        // lets try dynaminc approach 
        if(n<=2 && n>=0) return n;
        int x=1,y=2,z;
        for(int i=3;i<=n; i++){
            z=x+y;
            x=y;
            y=z;
        }
        return z;
    }
};