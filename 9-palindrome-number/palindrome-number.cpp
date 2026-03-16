class Solution {
public:
    bool isPalindrome(int x) {
        int orgi=x;
        long long rev=0,rem;
        while(x!=0){
            rem=x%10;
            if(rem<0) return false;
            rev=rev*10+rem;
            x=x/10;
        }
        if(rev==orgi) return true;
        return false;
    }
};