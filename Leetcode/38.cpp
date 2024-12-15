class Solution {
public:
    string transform(string cur) {
        string ret = "";

        int cnt = 0;
        char prev = cur[0];

        for (int i=0; i<cur.size(); i++) {
            if (cur[i] == prev) cnt++;
            else {
                string tmp = "";
                tmp += cnt + '0';
                tmp += prev;

                ret += tmp;
                prev = cur[i];
                cnt = 1;
            }
        }

        string tmp = "";
        tmp += cnt + '0';
        tmp += prev;

        ret += tmp;

        return ret;
    }

    string f(string cur, int cnt) {
        if (cnt == 0) return cur;
        return f(transform(cur), cnt-1);
    }

    string countAndSay(int n) {
        return f("1", n-1);
    }
};