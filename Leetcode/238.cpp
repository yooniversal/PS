class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> ret;
            
            int v = 1;
            int vExceptZero = 1;
            int zeroCnt = 0;
            for (auto& n : nums) {
                v *= n;
                if (n == 0) zeroCnt++;
                else vExceptZero *= n;
            }
            for (auto& n : nums) {
                if (n == 0) {
                    if (zeroCnt > 1) ret.push_back(0);
                    else ret.push_back(vExceptZero);
                } else {
                    ret.push_back(v / n);
                }
            }
            
            return ret;
        }
    };