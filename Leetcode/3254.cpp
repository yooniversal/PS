class Solution {
public:
    queue<int> q;

    int get_max() {
        queue<int> temp;
        int ret = 0, prev = 0;
        bool flag = true;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (flag) {
                if (cur - prev != 1 && prev != 0) {
                    flag = false;
                } else {
                    ret = max(ret, cur);
                }
            }
            temp.push(cur);
            prev = cur;
        }

        q = temp;

        if (flag) return ret;
        return -1;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ret;

        int target = 0;
        for (;target < k; target++) {
            q.push(nums[target]);
        }

        if (nums.size() == k) {
            ret.push_back(get_max());
            return ret;
        }

        for (;target<nums.size(); target++) {
            ret.push_back(get_max());
            q.pop();
            q.push(nums[target]);

            if (target == nums.size()-1) {
                ret.push_back(get_max());
            }
        }

        return ret;
    }
};