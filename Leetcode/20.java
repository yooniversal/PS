class Solution {

    static char[] openBrackets = {'(', '{', '['};

    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        
        for (int i=0; i<s.length(); i++) {
            char current = s.charAt(i);
            if (isOpenBracket(current)) {
                st.push(current);
                continue;
            }

            if (st.isEmpty()) return false;
            
            char savedBracket = st.pop();
            if (!match(savedBracket, current)) return false;
        }

        if (!st.isEmpty()) return false;

        return true;
    }

    boolean isOpenBracket(char c) {
        for (char b : openBrackets) {
            if (c == b) return true;
        }
        return false;
    }

    boolean match(char a, char b) {
        if (a == '(' && b == ')') return true;
        if (a == '{' && b == '}') return true;
        if (a == '[' && b == ']') return true;
        return false;
    }
}