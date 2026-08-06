/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        List<Node> arr = new ArrayList<>();
        for (Interval interval : intervals) {
            arr.add(new Node(interval.start, true));
            arr.add(new Node(interval.end, false));
        }
        Collections.sort(arr);

        int ret = 0, cur = 0;
        for (Node n : arr) {
            if (n.isStart) cur++;
            else cur--;
            ret = Math.max(ret, cur);
        }

        return ret;
    }

    class Node implements Comparable<Node> {
        int v;
        boolean isStart;

        public Node(int v, boolean isStart) {
            this.v = v;
            this.isStart = isStart;
        }

        @Override
        public int compareTo(Node next) {
            if (v != next.v) return Integer.compare(v, next.v);
            return Boolean.compare(isStart, next.isStart);
        }
    }
}
