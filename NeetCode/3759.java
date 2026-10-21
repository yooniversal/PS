class Solution {
    public int countElements(int[] nums, int k) {
        if (k == 0) return nums.length;

        Arrays.sort(nums);

        int target = -1;

        for (int i=nums.length-k; i>=0; i--) {
            if (nums[i] == nums[nums.length - k]) continue;
            target = i;
            break;
        }

        return target + 1;
    }
}
