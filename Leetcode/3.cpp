class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;

        for (int i=0; i<s.size(); i++) {
            int cnt = 0;
            set<char> chk;

            for (int j=i; j<s.size(); j++) {
                if (chk.find(s[j]) != chk.end()) break;
                chk.insert(s[j]);
                cnt++;
            }

            ret = max(ret, cnt);
        }

        return ret;
    }
};