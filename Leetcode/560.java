class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(0, 1);

        int ret = 0;
        int cur = 0;
        for (int n : nums) {
            cur += n;
            ret += cntMap.getOrDefault(cur - k, 0);
            cntMap.put(cur, cntMap.getOrDefault(cur, 0) + 1);
        }

        return ret;
    }
}
