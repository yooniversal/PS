class Solution {
public:
    int is_pass(int n, int x, vector<int>& quantities) {
        int cnt = 0;
        for (auto& q : quantities) {
            cnt += q % x == 0 ? q / x : q / x + 1;
        }
        
        if (cnt > n) return 1;
        return 0;
    }

    int binary_search(int n, vector<int>& quantities) {
        int ret = 987654321;
        int l = 1, r = 100000;

        while (l <= r) {
            int m = (l + r) / 2;
            int condition = is_pass(n, m, quantities);
            if (condition <= 0) {
                r = m - 1;
                if (condition == 0) ret = min(ret, m);
            } else {
                l = m + 1;
            }
        }

        return ret;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        return binary_search(n, quantities);
    }
};