class Solution {
    public:
        int minAnagramLength(string s) {
            for (int tsz=1; tsz<=s.size(); tsz++) {
                if (s.size() % tsz != 0) continue;
                
                vector<int> cnt(26, 0);
                bool flag = true;
                for (int i=0; i<s.size(); i += tsz) {
                    if (i == 0) {
                        initCnt(i, i+tsz, s, cnt);
                        continue;
                    }
    
                    if (!check(i, i+tsz, s, cnt)) {
                        flag = false;
                        break;
                    }
                }
    
                if (flag) return tsz;
            }
    
            return s.size();
        }
    
        void initCnt(int l, int r, const string& s, vector<int>& cnt) {
            for (int i=l; i<r; i++) {
                cnt[s[i] - 'a']++;
            }
        }
    
        bool check(int l, int r, const string& s, const vector<int>& cnt) {
            int chunkCnt[26];
            fill(chunkCnt, chunkCnt+26, 0);
            
            for (int i=l; i<r; i++) {
                chunkCnt[s[i] - 'a']++;
            }
    
            for (int i=0; i<26; i++) {
                if (chunkCnt[i] != cnt[i]) return false;
            }
    
            return true;
        }
    };