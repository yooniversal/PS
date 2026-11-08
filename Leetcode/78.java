class Solution {

    private List<List<Integer>> ret;

    public List<List<Integer>> subsets(int[] nums) {
        ret = new ArrayList<>();
        ret.add(Collections.emptyList());
        
        for (int i=0; i<nums.length; i++) process(nums, new ArrayList<>(), i);

        return ret;
    }

    private void process(int[] nums, List<Integer> cur, int start) {
        if (start >= nums.length) return;

        cur.add(nums[start]);
        ret.add(new ArrayList<>(cur));

        for (int i=start+1; i<nums.length; i++) {
            process(nums, cur, i);
            cur.remove(cur.size()-1);
        }
    }
}
