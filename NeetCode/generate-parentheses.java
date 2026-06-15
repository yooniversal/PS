class Solution {

    private static List<String> ret;
    private static int N;

    public List<String> generateParenthesis(int n) {
        ret = new ArrayList<>();
        N = n;

        DFS(0, 0, new StringBuilder());

        return ret;
    }

    public void DFS(int sz, int openCnt, StringBuilder sb) {
        if (sz == N*2) {
            if (openCnt == 0) ret.add(sb.toString());
            return;
        }

        if (openCnt > 0) {
            sb.append(")");
            DFS(sz+1, openCnt-1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }

        sb.append("(");
        DFS(sz+1, openCnt+1, sb);
        sb.deleteCharAt(sb.length() - 1);
    }
}
