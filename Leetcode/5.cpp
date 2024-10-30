class Solution {
public:
    int cache[1005][1005];
    string str;

    int f(int a, int b) {
        if (a<0 || b<0) return 0;
        if (abs(a-b) == 1 && str[a]==str[b]) return 1;
        if (a > b) return 0;
        if (a == b) return 1;
        int& ret = cache[a][b];
        if (ret != -1) return ret;
        ret = 0;

        if (str[a] != str[b]) ret = 0;
        else ret = f(a+1, b-1);

        return ret;
    }

    string longestPalindrome(string s) {
        memset(cache, -1, sizeof(cache));
        str = s;

        int cnt = 0;
        string ret;

        for (int i=0; i<s.size(); i++) {
            for (int j=i; j<s.size(); j++) {
                int v = f(i, j);
                if (v == 0) continue;
                if (cnt >= j - i + 1) continue;
                cnt = j - i + 1;
                ret = s.substr(i, j - i + 1);
            }
        }

        return ret;
    }
};