class Solution {
    public:
        const int INF = 987654321;
        int cache[100005];
    
        int f(vector<int>& tasks, int n) {
            if (n >= tasks.size()) return 0;
            int& ret = cache[n];
            if (ret != INF) return ret;
    
            if (tasks.size()-1 >= n+2 && tasks[n+2] == tasks[n]) {
                ret = min(ret, f(tasks, n+3) + 1);
            }
            if (tasks.size()-1 >= n+1 && tasks[n+1] == tasks[n]) {
                ret = min(ret, f(tasks, n+2) + 1);
            }
    
            return ret;
        }
    
        int minimumRounds(vector<int>& tasks) {
            sort(tasks.begin(), tasks.end());
            if (!isValid(tasks)) return -1;
    
            for (int i=0; i<100005; i++) cache[i] = INF;
    
            return f(tasks, 0);
        }
    
        bool isValid(vector<int>& tasks) {
            int prev = tasks[0];
            int cnt = 1;
    
            for (int i=1; i<tasks.size(); i++) {
                if (prev == tasks[i]) {
                    cnt++;
                    continue;
                }
    
                if (cnt <= 1) return false;
    
                prev = tasks[i];
                cnt = 1;
            }
    
            if (cnt <= 1) return false;
    
            return true;
        }
    };