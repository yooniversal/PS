class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        List<Node> list = new ArrayList<>();
        for (int i=0; i<nums.length; i++) {
            list.add(new Node(nums[i], i));
        }
        
        Collections.sort(list);

        for (int i=0; i<list.size()-1; i++) {
            if (list.get(i).num != list.get(i+1).num) continue;
            if (Math.abs(list.get(i).i - list.get(i+1).i) > k) continue;
            return true;
        }

        return false;
    }

    class Node implements Comparable<Node> {
        int num;
        int i;

        public Node(int num, int i) {
            this.num = num;
            this.i = i;
        }

        @Override
        public int compareTo(Node other) {
            if (this.num != other.num) {
                return Integer.compare(this.num, other.num);
            }
            return Integer.compare(this.i, other.i);
        }
    }
}