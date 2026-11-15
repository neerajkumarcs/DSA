class Solution {
public:
    bool isAnagram(string s, string t) {
    // solving using hashmap
    if(s.size()!=t.size()) return false;
    unordered_map<char,int> m1;
    for(int i=0; i<s.size(); i++){
        m1[s[i]]++;
    }    
    // second method using only one hash map
    for(int i=0; i<t.size(); i++){
        char ch=t[i];
        if(m1.find(ch)!=m1.end()){
            int fre=m1[ch];
            if(fre>1)m1[ch]--;
            else m1.erase(ch);
        }
        else return false;
    }
    return true;
    }
};