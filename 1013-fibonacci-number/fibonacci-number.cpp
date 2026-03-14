class Solution {
public:
    int fib(int n) {
        if(n<=0) return 0; // for defending error
        if(n==1 || n==2) return 1; // first 2 numbers 
        return fib(n-1)+fib(n-2); // recurssive calls yaha pe hai 
    }
};