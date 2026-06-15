class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<Integer> dup = new ArrayList<>();
        
        for (int i=0; i<intervals.length; i++) {
            if (intervals[i][1] < newInterval[0] || newInterval[1] < intervals[i][0]) continue;
            dup.add(i);
        }

        List<Pair> ret = new ArrayList<>();

        if (dup.size() == 0) {
            // 겹치는게 없음
            ret.add(new Pair(newInterval[0], newInterval[1]));
            for (int i=0; i<intervals.length; i++) {
                ret.add(new Pair(intervals[i][0], intervals[i][1]));
            }
            Collections.sort(ret);
        } else {
            // 처음
            for (int i=0; i<dup.get(0); i++) {
                ret.add(new Pair(intervals[i][0], intervals[i][1]));
            }

            // 중간 (겹침)
            List<Integer> arr = new ArrayList<>();
            arr.add(newInterval[0]);
            arr.add(newInterval[1]);
            for (int d : dup) {
                arr.add(intervals[d][0]);
                arr.add(intervals[d][1]);
            }
            Collections.sort(arr);
            ret.add(new Pair(arr.get(0), arr.get(arr.size()-1)));

            // 끝
            for (int i=dup.get(dup.size()-1)+1; i<intervals.length; i++) {
                ret.add(new Pair(intervals[i][0], intervals[i][1]));
            }
        }

        int[][] result = new int[ret.size()][2];
        for (int i=0; i<ret.size(); i++) {
            result[i][0] = ret.get(i).x;
            result[i][1] = ret.get(i).y;
        }

        return result;
    }

    class Pair implements Comparable<Pair> {
        int x, y;
        
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.x < other.x) return -1;
            if (this.y < other.y) return -1;
            return 1;
        }
    }
}
