class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        boolean[] chk = new boolean[10];

        DFS(ret, chk, new ArrayList<>(), 0, nums);
        return ret;
    }

    public void DFS(List<List<Integer>> ret, boolean[] chk, List<Integer> cur, int size, int[] nums) {
        if (size >= nums.length) {
            ret.add(new ArrayList<>(cur));
            return;
        }

        for (int i=0; i<nums.length; i++) {
            if (chk[i]) continue;
            chk[i] = true;
            cur.add(nums[i]);
            DFS(ret, chk, cur, size+1, nums);
            cur.remove(cur.size()-1);
            chk[i] = false;
        }
    }
}
