class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int ret = 0;

        int sum = 0;
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int n : nums) {
            if (n % 2 != 0) sum++;

            ret += map.getOrDefault(sum - k, 0);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        
        return ret;
    }
}
