class Solution {

    private static List<List<Integer>> ret;
    private static boolean[] chk;

    public List<List<Integer>> subsets(int[] nums) {
        ret = new ArrayList<>();
        chk = new boolean[21];
        ret.add(List.of());

        nums = Arrays.stream(nums)
            .distinct()
            .toArray();

        dfs(nums, new ArrayList<>(), 0);

        return ret;
    }

    public void dfs(int[] nums, List<Integer> cur, int start) {
        if (cur.size() == nums.length) {
            return;
        }

        for (int i=start; i<nums.length; i++) {
            int n = nums[i];
            System.out.println(n);
            if (chk[n+10]) continue;
            chk[n+10] = true;
            cur.add(n);

            ret.add(new ArrayList<>(cur));
            dfs(nums, cur, i+1);

            cur.remove(cur.size()-1);
            chk[n+10] = false;
        }
    }
}
