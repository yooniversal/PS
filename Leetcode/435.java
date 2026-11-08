class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

        int ret = 0;
        int left = 0;
        for (int i=1; i<intervals.length; i++) {
            if (isDup(intervals[left], intervals[i])) {
                ret++;
                continue;
            }

            left = i;
        }

        return ret;
    }

    private boolean isDup(int[] a, int[] b) {
        return b[0] < a[1];
    }
}
