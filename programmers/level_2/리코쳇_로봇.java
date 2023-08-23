import java.util.*;

class Solution {
    
    static int INF = 100000009;
    static int[] dx = new int[]{0, 0, 1, -1};
    static int[] dy = new int[]{1, -1, 0, 0};
    static int[][] chk = new int[101][101];
    static int n, m;
    
    public int solution(String[] board) {
        for(int i=0; i<101; ++i) for (int j=0; j<101; ++j) {
            chk[i][j] = INF;
        }
        n = board.length;
        m = board[0].length();
        return solve(board);
    }
    
    static int solve(String[] board) {
        Queue<Stat> q = new LinkedList<>();
        
        for(int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if(board[i].charAt(j) == 'R') {
                q.offer(new Stat(i, j, 0));
                break;
            }
        }
        
        while(!q.isEmpty()) {
            Stat cur = q.peek(); q.remove();
            
            if(board[cur.x].charAt(cur.y) == 'G')
                return cur.cnt;
            
            for(int i=0; i<4; ++i) {
                int nx = cur.x, ny = cur.y;
                while(true) {
                    nx += dx[i]; ny += dy[i];
                    if(OOB(nx, ny) || board[nx].charAt(ny) == 'D') {
                        nx -= dx[i]; ny -= dy[i];
                        break;
                    }
                }
                
                if(chk[nx][ny] <= cur.cnt+1) continue;
                chk[nx][ny] = cur.cnt+1;
                q.offer(new Stat(nx, ny, cur.cnt+1));
            }
        }
        
        return -1;
    }
    
    static boolean OOB(int x, int y) {
        return x<0 || x>=n || y<0 || y>=m;
    }
    
    static class Stat {
        public int x;
        public int y;
        public int cnt;
        
        public Stat(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}