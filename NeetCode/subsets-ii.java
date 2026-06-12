class Solution {

    private static Set<List<Integer>> chkSet;
    private static List<List<Integer>> ret;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        chkSet = new HashSet<>();
        ret = new ArrayList<>();

        // List<Integer> emptyList = List.of();
        // chkSet.add(emptyList);
        // ret.add(emptyList);

        getSubsets(nums, new ArrayList<>(), 0);

        return ret;
    }

    public void getSubsets(int[] nums, List<Integer> cur, int start) {
        List<Integer> sortedCur = cur.stream().sorted().toList();
        if (!chkSet.contains(sortedCur)) {
            chkSet.add(sortedCur);
            ret.add(sortedCur);
        }

        if (start >= nums.length) return;

        cur.add(nums[start]);
        getSubsets(nums, cur, start+1);

        cur.remove(cur.size()-1);
        getSubsets(nums, cur, start+1);
    }
}
