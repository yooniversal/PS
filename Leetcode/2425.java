class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int ret = 0;
        for (int num : nums1) {
            if (nums2.length % 2 == 1) ret ^= num;
        }
        for (int num : nums2) {
            if (nums1.length % 2 == 1) ret ^= num;
        }
        return ret;
    }
}