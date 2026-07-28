class Solution {
    private List<List<Integer>> ret;
    private boolean[] visited;

    public List<List<Integer>> permute(int[] nums) {
        ret = new ArrayList<>();
        visited = new boolean[nums.length];

        dfs(nums, new ArrayList<>());
        return ret;
    }

    private void dfs(int[] nums, List<Integer> current) {
        if (current.size() == nums.length) {
            ret.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            current.add(nums[i]);

            dfs(nums, current);

            current.remove(current.size() - 1);
            visited[i] = false;
        }
    }
}
