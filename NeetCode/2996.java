class Solution {
    public int missingInteger(int[] nums) {
        Set<Integer> set = new HashSet<>();
        
        int prev = nums[0], sum = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (nums[i] - prev == 1) {
                sum += nums[i];
                prev = nums[i];
            } else {
                break;
            }
        }

        for (int n : nums) set.add(n);

        while (set.contains(sum)) sum++;

        return sum;
    }
}
