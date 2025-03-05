public class Solution {
    public void rotate(int[] nums, int k) {
        Stack<Integer> st = new Stack<>();
        Queue<Integer> q = new LinkedList<>();

        k %= nums.length;

        int i = 0;
        for (i=nums.length-1; k > 0; k--, i--) {
            st.push(nums[i]);
        }

        for (int j=0; j<=i; j++) {
            q.offer(nums[j]);
        }

        i = 0;
        while (!st.isEmpty()) {
            nums[i++] = st.pop();
        }
        while (!q.isEmpty()) {
            nums[i++] = q.poll();
        }
    }
}
