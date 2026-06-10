class Solution {

    private static int[] cache;

    public int climbStairs(int n) {
        cache = new int[50];
        for (int i=0; i<50; i++) cache[i] = -1;

        return f(n);
    }

    public int f(int cur) {
        if (cur <= 0) return 0;
        if (cur == 1) return 1;
        if (cur == 2) return 2;
        if (cache[cur] != -1) return cache[cur];
        cache[cur] = 0;

        cache[cur] = f(cur-1) + f(cur-2);

        return cache[cur];
    }
}
