class Solution {
    public int jump(int[] nums) {
        boolean[] chk = new boolean[nums.length];
        chk[0] = true;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});

        int ret = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int curPosition = cur[0];
            int cnt = cur[1];

            if (curPosition == nums.length-1) {
                ret = cnt;
                break;
            }

            for (int i=curPosition+1; i<=curPosition+nums[curPosition] && i<nums.length; i++) {
                if (chk[i]) continue;
                chk[i] = true;
                q.add(new int[]{i, cnt + 1});
            }
        }

        return ret;
    }
}
