class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }

            string temp = "";

            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            if (temp == "") continue;

            if (ans == "") {
                ans += temp;
            }
            else {
                temp += ' ';
                ans.insert(0, temp);
            }
        }

        return ans;
    }
};