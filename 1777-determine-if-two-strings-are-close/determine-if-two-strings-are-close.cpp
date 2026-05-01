class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        // string st1=word1, st2=word2;
        // sort(st1.begin(), st1.end());
        // sort(st2.begin(), st2.end());
        // if(st1!=st2) return false;
        // return true;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i=0; i<word1.length() ; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        // compare mp1 and mp2 just ele.first(characters)
        for(auto x: mp1){ // just to check all letters present in both words
            char ch=x.first;
            if(mp2.find(ch)==mp2.end()) return false;
        }
        unordered_map<int, int> mp3;
        unordered_map<int, int> mp4;
        for(auto x:mp1){
            int freq=x.second;
            mp3[freq]++;
        }
         for(auto x:mp2){
            int freq=x.second;
            mp4[freq]++;
        }
        // now compare mp3 and mp4 
        for(auto ele: mp3){
            int key=ele.first;
            int val=ele.second;
            if(mp4.find(key)==mp4.end()) return false;
            if(mp4[key]!=mp3[key]) return false;
        }
        return true;
    }
};