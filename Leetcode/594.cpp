class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ret = 0;
        map<int, int> m;

        for (auto& n : nums) {
            m[n]++;
        }

        for (auto& n : nums) {
            if (m[n+1] == 0) continue;
            ret = max(ret, m[n] + m[n+1]);
        }

        return ret;
    }
};