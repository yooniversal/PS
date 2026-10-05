class Solution {

    private boolean[] chk;

    public int scoreOfParentheses(String s) {
        chk = new boolean[s.length()];
        return DFS(s, 0) / 2;
    }

    private int DFS(String s, int cur) {
        if (cur >= s.length()) return 0;
        if (s.charAt(cur) == ')') {
            chk[cur] = true;
            if (s.charAt(cur-1) == '(') return 1;
            return 0;
        }

        int ret = 0;

        for (int i=cur; i<s.length(); i++) {
            if (chk[i]) continue;
            chk[i] = true;

            if (s.charAt(i) == ')') break;

            ret += DFS(s, i+1);
        }

        return ret * 2;
    }
}
