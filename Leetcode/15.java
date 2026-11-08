class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        nums = Arrays.stream(nums)
            .sorted()
            .toArray();

        List<List<Integer>> ret = new ArrayList<>();

        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            int v = cntMap.getOrDefault(nums[i], 0);
            cntMap.put(nums[i], v + 1);
        }

        for (int i=0; i<nums.length; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (int j=i+1; j<nums.length; j++) {
                if (j>i+1 && nums[j] == nums[j-1]) continue;

                int target = -(nums[i] + nums[j]);
                if (nums[j] > target) continue;

                if (cntMap.containsKey(target)) {
                    int required = 1;
                    if (target == nums[i]) required++;
                    if (target == nums[j]) required++;

                    if (cntMap.get(target) >= required) {
                        ret.add(List.of(nums[i], nums[j], target));
                    }
                }
            }
        }

        return ret;
    }
}
