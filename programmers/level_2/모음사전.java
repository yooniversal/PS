class Solution {
    
    static String target;
    static int cnt;
    static boolean finish;
    
    public int solution(String word) {
        target = word;
        dfs("A");
        return cnt;
    }
    
    public void dfs(String cur) {
        ++cnt;
        if (cur.equals(target)) {
            finish = true;
            return;
        }
        
        if (cur.length() < 5) {
            String nextStr = cur + "A";
            dfs(nextStr);
            if (finish) return;
        }
        
        if (cur.charAt(cur.length()-1) == 'U') return;
        
        String nextStr = cur.substring(0, cur.length()-1) + next(cur.charAt(cur.length()-1));
        dfs(nextStr);
    }
    
    public String next(char cur) {
        if (cur == 'A') return "E";
        if (cur == 'E') return "I";
        if (cur == 'I') return "O";
        return "U";
    }
}