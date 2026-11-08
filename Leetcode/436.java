class Solution {
    public int[] findRightInterval(int[][] intervals) {
        List<Pair> arr = new ArrayList<>();
        for (int i=0; i<intervals.length; i++) {
            Pair p = new Pair(intervals[i][0], intervals[i][1], i);
            arr.add(p);
        }
        arr.sort((l, r) -> l.a - r.a);

        int[] ret = new int[intervals.length];
        for (Pair p : arr) {
            int l = 0, r = intervals.length - 1;
            int target = -1;
            while (l <= r) {
                int m = (l + r) / 2;

                if (p.b <= arr.get(m).a) {
                    target = arr.get(m).i;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            ret[p.i] = target;
        }

        return ret;
    }

    static class Pair {
        int a, b, i;
        
        public Pair(int a, int b, int i) {
            this.a = a;
            this.b = b;
            this.i = i;
        }
    }
}
