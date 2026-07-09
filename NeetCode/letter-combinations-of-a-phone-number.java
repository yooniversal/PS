class Solution {

    private String[] abc = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return List.of();
        List<String> ret = new ArrayList<>();

        String[] strs = new String[digits.length()];
        for (int i=0; i<digits.length(); i++) {
            char d = digits.charAt(i);
            int n = (int)(d - '0');
            strs[i] = abc[n];
        }

        for (int i=0; i<strs[0].length(); i++) {
            DFS(ret, strs, 0, i, new StringBuilder());
        }

        return ret;
    }

    public void DFS(List<String> ret, String[] strs, int cur, int i, StringBuilder sb) {
        if (cur >= strs.length-1) {
            sb.append(strs[cur].charAt(i));
            ret.add(sb.toString());
            sb.deleteCharAt(sb.length() - 1);
            return;
        }

        for (int t=0; t<strs[cur+1].length(); t++) {
            sb.append(strs[cur].charAt(i));
            DFS(ret, strs, cur+1, t, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
