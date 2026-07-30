class Solution {
    public int evalRPN(String[] tokens) {
        Stack<String> st = new Stack<>();
        
        for (String t : tokens) {
            if (t.equals("+")) {
                int a = Integer.valueOf(st.pop());
                int b = Integer.valueOf(st.pop());
                st.add(String.valueOf(b + a));
            } else if (t.equals("-")) {
                int a = Integer.valueOf(st.pop());
                int b = Integer.valueOf(st.pop());
                st.add(String.valueOf(b - a));
            } else if (t.equals("*")) {
                int a = Integer.valueOf(st.pop());
                int b = Integer.valueOf(st.pop());
                st.add(String.valueOf(b * a));
            } else if (t.equals("/")) {
                int a = Integer.valueOf(st.pop());
                int b = Integer.valueOf(st.pop());
                st.add(String.valueOf(b / a));
            } else {
                st.add(t);
            }
        }

        return Integer.valueOf(st.pop());
    }
}
