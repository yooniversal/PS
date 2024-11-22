class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            bool flag = true;
            for (int j=i, z=(i+1) % nums.size(), cnt=0; cnt<nums.size()-1; cnt++) {
                if (nums[j] > nums[z]) {
                    flag = false;
                    break;
                }

                j = (j+1) % nums.size();
                z = (z+1) % nums.size();
            }
            if (flag) return true;
        }
        return false;
    }
};