class Solution {
    public:
        const int INF = 987654321;
        int cache[1005];
    
        int f(vector<int>& cost, int n) {
                if (n >= cost.size()) return 0;
                int& ret = cache[n];
                if (ret != INF) return ret;
    
                ret = min(ret, f(cost, n+1) + cost[n]);
                ret = min(ret, f(cost, n+2) + cost[n]);
                
                return ret;
            }
    
        int minCostClimbingStairs(vector<int>& cost) {
            for (int i=0; i<1005; i++) cache[i] = INF;
            return min(f(cost, 0), f(cost, 1));
        }
    };