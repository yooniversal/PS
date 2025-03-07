class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int num : nums) {
            if (!map.containsKey(num)) {
                map.put(num, 1);
                continue;
            }
            map.put(num, map.get(num) + 1);
        }

        for (int num : nums) {
            if (map.get(num) == 1) return num;
        }

        return -1;
    }
}