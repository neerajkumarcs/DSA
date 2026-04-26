class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> result;

        // check all 3-digit even numbers
        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> temp = freq;

            if (temp[a]-- > 0 && temp[b]-- > 0 && temp[c]-- > 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};