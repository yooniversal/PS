class Solution {
public:
    const int FANCY_CNT = 3;

    string makeFancyString(string s) {
        string ret = "";

        int cnt = 0;
        for (int i=0; i<s.size(); i++) {
            if (i == 0 || s[i-1] != s[i]) {
                cnt = 1;
                ret += s[i];
                continue;
            }

            if (++cnt < FANCY_CNT) {
                ret += s[i];
            }
        }

        return ret;
    }
};