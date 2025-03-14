class Solution {
    public:
        bool isAnagram(string s, string t) {
            int sCnt[26], tCnt[26];
            for (int i=0; i<26; i++) {
                sCnt[i] = tCnt[i] = 0;
            }
    
            for (int i=0; i<s.size(); i++) {
                sCnt[s[i] - 'a']++;
            }
            for (int i=0; i<t.size(); i++) {
                tCnt[t[i] - 'a']++;
            }
    
            for (int i=0; i<26; i++) {
                if (sCnt[i] != tCnt[i]) return false;
            }
    
            return true;
        }
    };