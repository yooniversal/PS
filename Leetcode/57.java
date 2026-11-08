class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) return new int[][]{newInterval};
        List<int[]> tmp = new ArrayList<>();

        int start = -1, end = -1;
        for (int i=0; i<intervals.length; i++) {
            if (isDup(intervals[i], newInterval)) {
                if (start == -1) start = i;
                end = i;
            }
        }

        if (start == -1 && end == -1) {
            for (int i=0; i<intervals.length; i++) {
                tmp.add(intervals[i]);
            }
            tmp.add(newInterval);
            tmp.sort((a, b) -> a[0] - b[0]);
        } else {
            boolean flag = true;
            for (int i=0; i<intervals.length; i++) {
                if (start <= i && i <= end) {
                    if (flag) {
                        tmp.add(new int[]{
                            Math.min(intervals[start][0], newInterval[0]),
                            Math.max(intervals[end][1], newInterval[1])
                        });
                        flag = false;
                    }
                } else {
                    tmp.add(intervals[i]);
                }
            }
        }

        int[][] ret = new int[tmp.size()][2];
        for (int i=0; i<tmp.size(); i++) {
            ret[i] = tmp.get(i);
        }

        return ret;
    }

    private boolean isDup(int[] u, int[] v) {
        if (u[0] < v[0] && u[1] < v[0]) return false;
        if (u[0] > v[1] && u[1] > v[1]) return false;
        return true;
    }
}
