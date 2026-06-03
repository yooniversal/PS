class Solution {
    public int evalRPN(String[] tokens) {
        int ret = 0;
        Stack<Integer> st = new Stack<>();
        
        for (String token : tokens) {
            if (token.equals("+")) {
                int a = st.pop();
                int b = st.pop();
                st.push(b+a);
            } else if (token.equals("-")) {
                int a = st.pop();
                int b = st.pop();
                st.push(b-a);
            } else if (token.equals("*")) {
                int a = st.pop();
                int b = st.pop();
                st.push(b*a);
            } else if (token.equals("/")) {
                int a = st.pop();
                int b = st.pop();
                st.push(b/a);
            } else {
                int v = Integer.parseInt(token);
                st.push(v);
            }
        }

        return st.pop();
    }
}
