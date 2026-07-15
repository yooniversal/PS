class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((v1, v2) -> v1 - v2);
        for (int n : nums) {
            pq.add(n);
            if (pq.size() > k) pq.poll();
        }

        int ret = pq.poll();
        while (!pq.isEmpty()) pq.poll();
        return ret;
    }
}
