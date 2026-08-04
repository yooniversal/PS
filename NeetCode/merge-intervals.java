class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        List<int[]> tmp = new ArrayList<>();
        int[] bef = intervals[0];
        for (int i=1; i<intervals.length; i++) {
            if (isDup(bef, intervals[i])) {
                bef[0] = Math.min(bef[0], intervals[i][0]);
                bef[1] = Math.max(bef[1], intervals[i][1]);
            } else {
                tmp.add(bef);
                bef = intervals[i];
            }
        }
        tmp.add(bef);

        int[][] ret = new int[tmp.size()][2];
        for (int i=0; i<tmp.size(); i++) ret[i] = tmp.get(i);

        return ret;
    }

    private boolean isDup(int[] a, int[] b) {
        if (a[0] == b[0]) return true;
        if (a[1] == b[0]) return true;
        if (b[0] < a[1]) return true;
        return false;
    }
}
