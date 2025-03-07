class Solution {
    public int[] singleNumber(int[] nums) {
        int[] ret = new int[2];
        int retIndex = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        
        for (int num : nums) {
            if (!map.containsKey(num)) {
                map.put(num, 1);
                continue;
            }
            map.put(num, map.get(num) + 1);
        }

        for (int num : nums) {
            if (map.get(num) == 1) {
                ret[retIndex++] = num;
            }
        }

        return ret;
    }
}