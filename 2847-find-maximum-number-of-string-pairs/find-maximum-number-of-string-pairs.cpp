class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int mxpair=0;
        unordered_set<string> s;
        for(int i=0; i<n; i++){
            s.insert(words[i]); // here all strings in word to store in set
        }
        for(int i=0; i<n; i++){
         string st =words[i];
         reverse(st.begin(), st.end());
         if(words[i]==st) continue; //  * Note->here to handle the condition of pallindrome string
         if(s.find(st)!=s.end()){
            mxpair++;
            s.erase(words[i]);
         }
        }
        return mxpair;
    }
};