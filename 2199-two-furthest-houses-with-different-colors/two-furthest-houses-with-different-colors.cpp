class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        // Case 1
        if (colors[0] != colors[n - 1]) {
            return n - 1;
        }

        int i = 0, j = n - 1;

        // Find from left
        while (i < n && colors[i] == colors[0]) {
            i++;
        }

        // Find from right
        while (j >= 0 && colors[j] == colors[n - 1]) {
            j--;
        }

        return max(n - 1 - i, j);
    }
};