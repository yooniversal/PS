class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;

        for (auto& n : nums) {
            if (m[n] == 0) {
                m[n]++;
                continue;
            }
            return true;
        }

        return false;
    }
};