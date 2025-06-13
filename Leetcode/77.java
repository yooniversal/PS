class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ret = new ArrayList<>();

        f(ret, new ArrayList<>(), n, k, 0);

        return ret;
    }

    public void f(List<List<Integer>> ret, List<Integer> cur, int n, int k, int start) {
        if (cur.size() >= k) {
            ret.add(cur.stream().collect(Collectors.toList()));
            return;
        }
        if (start >= n) return;

        for (int i=start+1; i<=n; i++) {
            cur.add(i);
            f(ret, cur, n, k, i);
            cur.remove(cur.size()-1);
        }
    }
}