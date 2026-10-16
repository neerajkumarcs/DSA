class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;

        while (i < n) {
            // Extra spaces skip karo
            while (i < n && s[i] == ' ') {
                i++;
            }

            string temp = "";

            // Pehle ek word nikalo
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            if (temp != "") {
                // Naye word ko purane answer ke front mein
                // directly insert karne ke bajaye, naya result banao
                if (ans == "") {
                    ans = temp;
                } else {
                    ans = temp + " " + ans;
                }
            }
        }

        return ans;
    }
};