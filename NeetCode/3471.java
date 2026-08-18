class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] cnt = new int[51];
        for (int i=0; i<=nums.length-k; i++) {
            boolean[] chk = new boolean[51];
            for (int j=i; j<i+k && j<nums.length; j++) {
                if (chk[nums[j]]) continue;
                chk[nums[j]] = true;
                cnt[nums[j]]++;
            }
        }

        int ret = -1;
        for (int i=0; i<51; i++) {
            if (cnt[i] == 1) {
                ret = Math.max(ret, i);
            }
        }

        return ret;
    }
}
