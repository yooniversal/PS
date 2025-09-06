class Solution {
public:
    int getFourExp(long long v) {
        int ret = 0;
        long long tmp = 1;
        while (v > tmp) {
            ret++;
            tmp *= 4;
        }
        if (v == tmp) ret++;
        return ret;
    }

    long long getBeforeCnt(long long v) {
        long long n = getFourExp(v);
        if (n == 0LL) return 0LL;

        long long ret = n * (v - (1LL << (2*(n-1))) + 1);
        long long tmp = 1;
        for (int i=0; i<=n-1; i++) {
            if (i == n-1) {
                ret += (n-1) * (1LL << (2*(n-1)));
            } else {
                ret -= tmp;
                tmp *= 4;
            }
        }
        
        return ret;
    }

    long long solve(vector<int>& query) {
        long long leftCnt = getBeforeCnt(query[0] - 1);
        long long rightCnt = getBeforeCnt(query[1]);
        return (rightCnt - leftCnt) % 2 == 0 ?
            (rightCnt - leftCnt) / 2 : (rightCnt - leftCnt) / 2 + 1;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ret = 0;
        for (auto& q : queries) {
            ret += solve(q);
        }
        return ret;
    }
};