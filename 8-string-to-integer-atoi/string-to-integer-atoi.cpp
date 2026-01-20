class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long long num = 0; 
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
