class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);

        int ret = 0;
        int cur = 0;
        for (int i=0; i<nums.length; i++) {
            if (nums[i] == 0) cur--;
            else cur++;

            if (map.containsKey(cur)) {
                ret = Math.max(ret, i-map.get(cur));
            } else {
                map.put(cur, i);
            }
        }

        return ret;
    }
}
