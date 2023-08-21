package programmers;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        
        int[] a = new int[sequence.length+1];
        a[0] = 0;
        a[1] = sequence[0];
        for(int i=2; i<a.length; ++i) {
            a[i] = a[i-1] + sequence[i-1];
        }
        
        int ansLen = 1000005;
        answer[0] = 1000005;
        
        for(int i=a.length-1; i>=1; --i) {
            if(a[i] < k) break;
            int b = lb(a, 0, i-1, a[i]-k);
            
            if(a[i] - a[b] != k || b == -1) continue;
            if(ansLen < i-b) continue;
            if(ansLen == b-i) {
                if(answer[0] < i) continue;
                answer[0] = b;
                answer[1] = i-1;
            } else {
                ansLen = i-b;
                answer[0] = b;
                answer[1] = i-1;
            }
        }
        
        return answer;
    }
    
    public static int lb(int[] a, int l, int r, int x) {
        int ret = -1;
        while(l <= r) {
            int m = (l+r) / 2;
            if(a[m] <= x) {
                ret = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ret;
    }
}
