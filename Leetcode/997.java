class Solution {
    public int findJudge(int n, int[][] trust) {
        List<List<Integer>> e = new ArrayList<>();
        for (int i=0; i<n+1; i++) e.add(new ArrayList<>());

        int[] inDegree = new int[n+1];

        for (int[] t : trust) {
            int a = t[0], b = t[1];
            e.get(a).add(b);
            inDegree[b]++;
        }

        for (int i=1; i<=n; i++) {
            if (inDegree[i] != n-1) continue;
            if (e.get(i).isEmpty()) return i;
        }

        return -1;
    }
}
