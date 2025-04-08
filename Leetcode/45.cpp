class Solution {
    public:
        bool chk[10005];
    
        int jump(vector<int>& nums) {
            queue<pair<int, int>> q; 
            q.push({0, 0});
    
            while (!q.empty()) {
                pair<int, int> top = q.front(); q.pop();
                int cur = top.first, cnt = top.second;
    
                if (cur >= nums.size()-1) return cnt;
                
                for (int i=1; i<=nums[cur]; i++) {
                    int next = cur + i;
                    if (next >= nums.size()-1) return cnt + 1;
                    if (chk[next] || nums[next] == 0) continue;
                    chk[next] = true;
                    q.push({next, cnt + 1});
                }
            }
    
            return -1;
        }
    };