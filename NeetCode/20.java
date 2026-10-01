class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> pair = new HashMap<>();
        pair.put('(', ')');
        pair.put('{', '}');
        pair.put('[', ']');

        Stack<Character> st = new Stack<>();

        for (int i=0; i<s.length(); i++) {
            if (pair.containsKey(s.charAt(i))) {
                st.push(s.charAt(i));
            } else {
                if (st.isEmpty()) return false;

                char top = st.pop();
                if (s.charAt(i) != pair.get(top)) return false;
            }
        }

        if (!st.isEmpty()) return false;

        return true;
    }
}
