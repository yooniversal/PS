class Solution {
    public void sortColors(int[] nums) {
        int[] cnt = new int[3];
        for (int n : nums) {
            cnt[n]++;
        }

        int cntIndex = 0;
        if (cnt[0] > 0) cntIndex = 0;
        else if (cnt[1] > 0) cntIndex = 1;
        else cntIndex = 2;

        for (int i=0; i<nums.length; i++) {
            nums[i] = cntIndex;
            cnt[cntIndex]--;
            while (cntIndex < 3 && cnt[cntIndex] == 0) cntIndex++;
        }
    }
}
