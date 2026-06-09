class Solution {

    private static Set<List<Integer>> retSet;

    public Solution() {
        retSet = new HashSet<>();
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        DFS(ret, new ArrayList<>(), nums, target, 0, 0);
        return ret;
    }

    public void DFS(List<List<Integer>> ret, List<Integer> selected, int[] nums, int target, int curSum, int cur) {
        if (cur >= nums.length || curSum > target) return;
        if (curSum == target) {
            List<Integer> newRet = new ArrayList<>(selected);
            if (retSet.contains(newRet)) return;
            retSet.add(newRet);
            ret.add(newRet);
            return;
        }

        selected.add(nums[cur]);
        DFS(ret, selected, nums, target, curSum + nums[cur], cur);
        DFS(ret, selected, nums, target, curSum + nums[cur], cur+1);
        selected.remove(selected.size()-1);
        DFS(ret, selected, nums, target, curSum, cur+1);
    }
}
