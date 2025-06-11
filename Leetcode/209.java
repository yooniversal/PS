class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ret = 100005;
        int subArrSum = nums[0];
        int currentLength = 1;
        
        for (int i=0, j=0; i<nums.length && j<nums.length;) {
            if (subArrSum >= target) {
                ret = Math.min(ret, currentLength);
                subArrSum -= nums[i++];
                currentLength--;
                if (i > j) {
                    if (j+1 < nums.length) subArrSum += nums[++j];
                    else break;
                    currentLength++;
                }
                continue;
            }

            if (j+1 < nums.length) subArrSum += nums[++j];
            else break;
            currentLength++;
        }

        if (ret == 100005) return 0;
        return ret;
    }
}