class Solution {
    
    static int[][][][] cache = new int[6][6][6][51];
    static String[] mir;
    static int INF = 100000009;
        
    public int solution(int[] picks, String[] minerals) {
        mir = minerals;
        for(int i=0; i<6; ++i) for(int j=0; j<6; ++j) {
            for(int k=0; k<6; ++k) for(int n=0; n<51; ++n) {
                cache[i][j][k][n] = -1;
            }
        }
            
        return f(picks[0], picks[1], picks[2], 0);
    }
    
    static int f(int d, int i, int s, int n) {
        if(d<0 || i<0 || s<0) return INF;
        if(d==0 && i==0 && s==0) return 0;
        // System.out.printf("** %d %d %d | n:%d\n", d, i, s, n);
        if(n >= mir.length) return 0;
        // System.out.printf("* %d %d %d | n:%d\n", d, i, s, n);
        if(cache[d][i][s][n] != -1) return cache[d][i][s][n];
        // System.out.printf("[] %d %d %d | n:%d\n", d, i, s, n);
        cache[d][i][s][n] = INF;
        cache[d][i][s][n] = Math.min(cache[d][i][s][n], f(d-1, i, s, n+5) + getMir(0, n));
        cache[d][i][s][n] = Math.min(cache[d][i][s][n], f(d, i-1, s, n+5) + getMir(1, n));
        cache[d][i][s][n] = Math.min(cache[d][i][s][n], f(d, i, s-1, n+5) + getMir(2, n));
        
        // System.out.printf("%d %d %d | n:%d -> %d\n", d, i, s, n, cache[d][i][s][n]);
        
        return cache[d][i][s][n];
    }
    
    static int mirId(String s) {
        if(s.equals("diamond")) return 0;
        if(s.equals("iron")) return 1;
        return 2;
    }
    
    static int getMir(int p, int n) {
        int ret = 0;
        for(int i=n; i<mir.length && i<n+5; ++i) {
            ret += stam(p, mirId(mir[i]));
        }
        return ret;
    }
    
    static int stam(int p, int m) {
        if(p == 0) {
            return 1;
        }
        if(p == 1) {
            if(m == 0) return 5;
            return 1;
        }
        if(m == 0) return 25;
        if(m == 1) return 5;
        return 1;
    }
}