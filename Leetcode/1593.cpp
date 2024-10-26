class Solution {
public:
    int ret = 1;
    set<string> a;

    void dfs(string& s, int cur, int cnt) {
        if (cur >= s.size()) {
            ret = max(ret, cnt);
            return;
        }

        for (int i=0; i<s.size() - cur; i++) {
            string str = s.substr(cur, i + 1);
            if (a.find(str) != a.end()) continue;
            a.insert(str);
            dfs(s, cur + i + 1, cnt + 1);     
            a.erase(str);  
        }        
    }

    int maxUniqueSplit(string s) {
        dfs(s, 0, 0);
        return ret;
    }
};