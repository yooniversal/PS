class Solution {
    public:
        const int INF = 987654321;
        int cache[30005][2];
    
        int f(vector<int>& prices, int a, int b) {
            if (a >= prices.size()) return 0;
            int& ret = cache[a][b];
            if (ret != -INF) return ret;
            ret = 0;
    
            if (b == 1) {
                ret = max(ret, f(prices, a+1, 0) + prices[a]);
                ret = max(ret, f(prices, a+1, 1));
            } else {
                ret = max(ret, f(prices, a+1, 0));
                ret = max(ret, f(prices, a+1, 1) - prices[a]);
            }
    
            return ret;
        }
    
        int maxProfit(vector<int>& prices) {
            for (int i=0; i<30005; i++) {
                cache[i][0] = cache[i][1] = -INF;
            }
            return f(prices, 0, 0);
        }
    };