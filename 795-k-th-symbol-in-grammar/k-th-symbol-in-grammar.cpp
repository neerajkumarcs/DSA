class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k%2==0){ //even -> flip previous one
        int previous=kthGrammar(n-1,k/2);
        if(previous==0) return 1;
        else return 0;
        }
        else { // in case odd k
        return kthGrammar(n-1,k/2+1);
        }
    }
};