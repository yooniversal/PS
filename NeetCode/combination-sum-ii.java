class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ret = new ArrayList<>();
        List<Integer> sortedNums = Arrays.stream(candidates)
            .sorted()
            .boxed()
            .toList();
        
        DFS(ret, new ArrayList<>(), sortedNums, target, 0, 0);
        return ret;
    }

    public void DFS(List<List<Integer>> ret, List<Integer> selected, List<Integer> nums, int target, int curSum, int start) {
        if (curSum == target) {
            ret.add(new ArrayList<>(selected));
            return;
        }
        
        for (int i=start; i<nums.size(); i++) {
            if (curSum + nums.get(i) > target) break; 
            if (i > start && nums.get(i).equals(nums.get(i - 1))) continue;

            selected.add(nums.get(i));
            DFS(ret, selected, nums, target, curSum + nums.get(i), i + 1);
            selected.remove(selected.size() - 1);
        }
    }
}
