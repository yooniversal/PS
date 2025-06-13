class Solution {
    static boolean[] chk = new boolean[10];

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();

        f(ret, new ArrayList<>(), nums);

        return ret;
    }

    public void f(List<List<Integer>> ret, List<Integer> cur, int[] nums) {
        if (cur.size() >= nums.length) {
            ret.add(cur.stream().collect(Collectors.toList()));
            return;
        }

        for (int i=0; i<nums.length; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            cur.add(nums[i]);
            f(ret, cur, nums);
            cur.remove(cur.size()-1);
            chk[i] = false;
        }
    }
}