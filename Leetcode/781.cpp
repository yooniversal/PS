class Solution {
    public:
        int cnt[1005];
    
        int numRabbits(vector<int>& answers) {
            int ret = 0;
    
            for (int& a : answers) {
                cnt[a]++;
            }
    
            for (int i=0; i<=1000; i++) {
                if (cnt[i] == 0) continue;
                int rem = cnt[i] % (i+1);
                if (rem > 0) {
                    cnt[i] -= rem;
                    cnt[i] += i+1;
                }
                ret += cnt[i];
            }
    
            return ret;
        }
    };