class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0;

        map<int, int> cnt_map;

        for (auto& n : nums) {
            cnt_map[n]++;
        }

        for (auto& n : nums) {
            int target = cnt_map[n];
            if (nums.size() % 2 == 0) {
                if (target >= nums.size() / 2) return n;
            } else {
                if (target > nums.size() / 2) return n;
            }
        }

        return 0;
    }
};