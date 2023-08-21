package programmers;

class Solution {
    public long solution(long r1, long r2) {
        long borderCnt = 0;
        for(long x=1; x<r1; ++x) {
            long y = (long) Math.floor(Math.sqrt(r1*r1 - x*x));
            if(y*y == r1*r1 - x*x) {
                ++borderCnt;
            }
        }
        
        return circle_dots(r2) - circle_dots(r1) + borderCnt*4 + 4;
    }
    
    static long circle_dots(long r) {
        return 4*quarter_circle_dots(r) - 4*(r+1) + 1;
    }
    
    static long quarter_circle_dots(long r) {
        long ret = 0;
        for(long x=0; x<=r; ++x) {
            long y = lb(0, r, (long) Math.sqrt(r*r - x*x));
            ret += y+1;
        }
        
        return ret;
    }
    
    static long lb(long l, long r, long x) {
        long ret = -1;
        while(l <= r) {
            long m = (l+r)/2;
            if(m <= x) {
                ret = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ret;
    }
}