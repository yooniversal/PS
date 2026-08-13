class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] ret = new int[nums.length-k+1];

        Map<Integer, Integer> cnt = new HashMap<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        int left = 0;
        for (int i=0; i<nums.length; i++) {
            if (i < k) {
                int currentCnt = cnt.getOrDefault(nums[i], 0);
                cnt.put(nums[i], currentCnt + 1);
                if (currentCnt == 0) pq.add(nums[i]);

                if (i == k-1) ret[0] = pq.peek();
            } else {
                cnt.put(nums[left], cnt.get(nums[left]) - 1);
                if (!pq.isEmpty() && pq.peek() == nums[left]) {
                    if (cnt.get(nums[left]) == 0) {
                        pq.poll();
                    }
                }
                
                while (!pq.isEmpty() && cnt.getOrDefault(pq.peek(), 0) == 0) pq.poll();

                int currentCnt = cnt.getOrDefault(nums[i], 0);
                cnt.put(nums[i], currentCnt + 1);
                if (currentCnt == 0) pq.add(nums[i]);

                ret[++left] = pq.peek();
            }
        }

        return ret;
    }
}
