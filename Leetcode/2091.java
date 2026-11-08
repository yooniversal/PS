class Solution {
    public int minimumDeletions(int[] nums) {
        int minn = 100005, maxx = -100005;
        int minIndex = -1, maxIndex = -1;
        for (int i=0; i<nums.length; i++) {
            if (nums[i] < minn) {
                minn = nums[i];
                minIndex = i;
            }
            if (nums[i] > maxx) {
                maxx = nums[i];
                maxIndex = i;
            }
        }

        int a = Math.min(minIndex, maxIndex);
        int b = Math.max(minIndex, maxIndex);

        int ret = (a + 1) + (nums.length - b);
        ret = Math.min(ret, b + 1);
        ret = Math.min(ret, nums.length - a);

        return ret;
    }
}
