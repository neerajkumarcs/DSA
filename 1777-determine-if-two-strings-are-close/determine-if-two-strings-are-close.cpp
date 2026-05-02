class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // =========================
        // STEP 0: Basic Check
        // =========================
        // If lengths are different → impossible to make them same
        if (word1.length() != word2.length()) return false;


        // =========================
        // STEP 1: Count frequency of each character
        // =========================
        // mp1 and mp2 store:
        // character → frequency
        unordered_map<char, int> mp1, mp2;

        for (int i = 0; i < word1.length(); i++) {
            mp1[word1[i]]++;   // count chars in word1
            mp2[word2[i]]++;   // count chars in word2
        }


        // =========================
        // STEP 2: Check same set of characters
        // =========================
        // IMPORTANT:
        // You can swap frequencies, BUT you cannot introduce new characters
        // So both strings must contain same unique characters

        for (auto x : mp1) {
            char ch = x.first;

            // if this character does NOT exist in word2 → impossible
            if (mp2.find(ch) == mp2.end()) return false;
        }


        // =========================
        // STEP 3: Build "frequency of frequency" maps
        // =========================
        // mp3 / mp4 store:
        // frequency → how many characters have this frequency

        unordered_map<int, int> mp3, mp4;

        // For word1
        for (auto x : mp1) {
            int freq = x.second;   // frequency of a character
            mp3[freq]++;           // count how many chars have this freq
        }

        // For word2
        for (auto x : mp2) {
            int freq = x.second;
            mp4[freq]++;
        }


        // =========================
        // STEP 4: Compare frequency distributions
        // =========================
        // KEY IDEA:
        // Same frequency must appear same number of times in both strings

        for (auto ele : mp3) {
            int key = ele.first;    // frequency (like 1,2,3...)
            int val = ele.second;   // how many chars have this freq

            // Case 1: frequency doesn't exist in word2
            if (mp4.find(key) == mp4.end()) return false;

            // Case 2: frequency exists but count mismatch
            if (mp4[key] != mp3[key]) return false;
        }


        // =========================
        // FINAL RESULT
        // =========================
        return true;
    }
};