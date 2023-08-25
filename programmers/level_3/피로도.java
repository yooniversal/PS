class Solution {
    
    static int[][] d;
    static int answer;
    static boolean[] chk;
    
    public int solution(int k, int[][] dungeons) {
        d = dungeons;
        chk = new boolean[d.length];
        dfs(k, 0, 0);
        return answer;
    }
    
    static void dfs(int k, int cnt, int loop) {
        if(k < 0) return;
        answer = Math.max(answer, cnt);
        
        for(int i=0; i<d.length; ++i) {
            if(chk[i]) continue;
            chk[i] = true;
            if(d[i][0] <= k) dfs(k-d[i][1], cnt+1, loop+1);
            dfs(k, cnt, loop+1);
            chk[i] = false;
        }
    }
}