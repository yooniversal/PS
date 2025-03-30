class Solution {
    public:
        const int INF = 987654321;
        int cache[50005][2];
    
        int f(vector<int>& prices, int fee, int a, int b) {
            if (a >= prices.size()) return 0;
            int& ret = cache[a][b];
            if (ret != -INF) return ret;
            ret = 0;
    
            if (b == 1) {
                ret = max(ret, f(prices, fee, a+1, 0) + prices[a] - fee);
                ret = max(ret, f(prices, fee, a+1, 1));
            } else {
                ret = max(ret, f(prices, fee, a+1, 0));
                ret = max(ret, f(prices, fee, a+1, 1) - prices[a]);
            }
    
            return ret;
        }
    
        int maxProfit(vector<int>& prices, int fee) {
            for (int i=0; i<50005; i++) {
                cache[i][0] = cache[i][1] = -INF;
            }
            return f(prices, fee, 0, 0);
        }
    };