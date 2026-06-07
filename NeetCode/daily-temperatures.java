class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] ret = new int[temperatures.length];

        Deque<Integer> st = new ArrayDeque<>();
        
        for (int i=0; i<temperatures.length; i++) {
            while (!st.isEmpty() && temperatures[i] > temperatures[st.peek()]) {
                int prev = st.peek();
                ret[prev] = i - prev;
                st.pop();
            }

            st.push(i);
        }

        return ret;
    }
}
