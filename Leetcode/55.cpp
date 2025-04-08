class Solution {
    public:
        bool chk[100005];
    
        bool canJump(vector<int>& nums) {
            queue<int> q; 
            q.push(0);
    
            while (!q.empty()) {
                int cur = q.front(); q.pop();
    
                if (cur >= nums.size()-1) return true;
                
                for (int i=1; i<=nums[cur]; i++) {
                    int next = cur + i;
                    if (next >= nums.size()-1) return true;
                    if (chk[next] || nums[next] == 0) continue;
                    chk[next] = true;
                    q.push(next);
                }
            }
    
            return false;
        }
    };