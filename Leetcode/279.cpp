class Solution {
    public:
        struct S {
            int n, cnt;
            S(int a, int b) {
                n = a; cnt = b; 
            }
        };
    
        int numSquares(int n) {
            queue<S> q;
    
            q.push(S(n, 0));
    
            while (!q.empty()) {
                S cur = q.front(); q.pop();
                if (cur.n == 0) return cur.cnt;
    
                for (int i=sqrt(cur.n); i>=1; i--) {
                    if (cur.n < i*i) continue;
                    q.push(S(cur.n - i*i, cur.cnt + 1));   
                }
            }
    
            return -1;
        }
    };