class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();

        for (int a : asteroids) {
            if (st.isEmpty()) {
                st.add(a);
            } else {
                if (st.peek() > 0) {
                    if (a > 0) {
                        st.add(a);
                    } else {
                        if (st.peek() < -a) {
                            while (!st.isEmpty() && st.peek() > 0 && st.peek() < -a) st.pop();
                            if (st.isEmpty() || st.peek() < 0) st.add(a);
                            else if (!st.isEmpty() && st.peek() == -a) st.pop();
                        } else {
                            if (!st.isEmpty() && st.peek() > 0 && st.peek() == -a) st.pop();
                        }
                    }
                } else {
                    st.add(a);
                }
            }
        }

        int[] ret = new int[st.size()];
        for (int i=ret.length-1; i>=0; i--) {
            ret[i] = st.pop();
        }

        return ret;
    }
}
