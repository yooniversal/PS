class Solution {

    private List<List<Integer>> ret;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        ret = new ArrayList<>();
        Arrays.sort(candidates);

        search(candidates, 0, new ArrayList<>(), 0, target);

        return ret;
    }

    private void search(int[] candidates, int start, List<Integer> cur, int sum, int target) {
        if (sum == target) {
            ret.add(new ArrayList<>(cur));
            return;
        }
        if (start >= candidates.length) return;

        for (int i=start; i<candidates.length; i++) {
            int v = candidates[i], times = 0;
            while (sum + v <= target) {
                cur.add(candidates[i]);
                
                search(candidates, i+1, cur, sum + v, target);

                v += candidates[i];
                times++;
            }

            for (int j=0; j<times; j++) {
                cur.remove(cur.size()-1);
            }
        }
    }
}
