class Solution {

    private boolean[] chk;
    private boolean ret;

    public boolean canJump(int[] nums) {
        chk = new boolean[1005];
        ret = false;

        jump(nums, 0);

        return ret;
    }

    private void jump(int[] nums, int cur) {
        if (cur >= nums.length) return;
        if (cur == nums.length-1) {
            ret = true;
            return;
        }
        if (chk[cur]) return;
        chk[cur] = true;

        for (int i=1; i<=nums[cur]; i++) {
            jump(nums, cur + i);
        }
    }
}
