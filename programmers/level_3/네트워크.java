class Solution {
    
    static int[] group;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        group = new int[n+1];
        for(int i=0; i<=n; ++i) 
            group[i] = i;
        
        for(int i=0; i<computers.length; ++i) {
            for(int j=0; j<n; ++j) {
                if(i==j) continue;
                if(computers[i][j] == 0) continue;
                makeUnion(i, j);
            }
        }
        
        for(int i=0; i<n; ++i) {
            // System.out.printf("find(%d)=%d\n", i, find(i));
            if(find(i) != i) continue;
            answer++;
        }
        
        return answer;
    }
    
    static int find(int a) {
        if(group[a] == a) return a;
        return group[a] = find(group[a]);
    }
    
    static void makeUnion(int a, int b) {
        a = find(a); b = find(b);
        if(a <= b) group[b] = a;
        else group[a] = b;
    }
}