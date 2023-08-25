import java.util.*;

class Solution {
    
    static int[][] e;
    static int size;
    static int INF = 987654321;
    static boolean[] chk;
    static int groupSize;
    static ArrayList<Integer> g = new ArrayList<>();
    
    public int solution(int n, int[][] wires) {
        int answer = INF;
        
        size = n;
        e = new int[n+1][n+1];
        for(int[] wire : wires) {
            int u = wire[0], v = wire[1];
            e[u][v] = e[v][u] = 1;
        }
        
        chk = new boolean[n+1];
        for(int[] wire : wires) {
            int u = wire[0], v = wire[1];
            e[u][v] = e[v][u] = 0;
            
            for(int i=1; i<=n; ++i)
                chk[i] = false;
            
            g.clear();
            for(int i=1; i<=n; ++i) {
                if(chk[i]) continue;
                chk[i] = true;
                groupSize = 0;
                dfs(i);
                g.add(groupSize);
            }
            
            answer = Math.min(answer, Math.abs(g.get(0) - g.get(1)));
                
            e[u][v] = e[v][u] = 1;
        }
        
        return answer;
    }
    
    static void dfs(int cur) {
        groupSize++;
        
        for(int i=1; i<=size; ++i) {
            if(i == cur) continue;
            if(chk[i]) continue;
            if(e[cur][i] == 0) continue;
            chk[i] = true;
            dfs(i);
        }
    }
}