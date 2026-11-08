class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int ret = 1;
        Map<Integer, Integer> cntMap = new HashMap<>();
        
        cntMap.put(nums[0], 1);
        for (int l=0, r=1; l<nums.length && r<nums.length; r++) {
            int rv = cntMap.getOrDefault(nums[r], 0) + 1;

            if (rv > k) {
                boolean flag = true;
                while (flag) {
                    if (nums[l] == nums[r]) flag = false;
                    cntMap.put(nums[l], cntMap.get(nums[l]) - 1);
                    l++;
                }
                cntMap.put(nums[r], k);
            } else {
                cntMap.put(nums[r], rv);
            }

            ret = Math.max(ret, r-l+1);
        }

        return ret;
    }
}
