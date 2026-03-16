class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false; // negative number never  because a number only one sign allowed 
        int orgi=x;
        long long rev=0,rem;
        while(x!=0){
            rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        if(rev==orgi) return true;
        return false;
    }
};