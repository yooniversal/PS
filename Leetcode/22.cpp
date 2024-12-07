class Solution {
public:
    vector<string> ret;

    void DFS(string& s, int open_cnt, int close_cnt) {
        if (open_cnt == 0 && close_cnt == 0) {
            ret.push_back(s);
            return;
        }

        if (open_cnt > 0) {
            s += "(";
            DFS(s, open_cnt - 1, close_cnt);
            s.pop_back();
        }
        if (close_cnt > 0 && open_cnt < close_cnt) {
            s += ")";
            DFS(s, open_cnt, close_cnt - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        DFS(s, n, n);
        return ret;
    }
};