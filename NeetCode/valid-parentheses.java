class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if (check(st, c)) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.isEmpty();
    }

    public boolean check(Deque<Character> st, char c) {
        if (st.isEmpty()) return false;
        if (
            (c == ']' && st.peek() == '[')
            || (c == '}' && st.peek() == '{')
            || (c == ')' && st.peek() == '(')
        ) {
            return true;
        }

        return false;
    }
}
