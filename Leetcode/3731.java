class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int minn = 101, maxx = 0;
        boolean[] chk = new boolean[105];
        for (int n : nums) {
            minn = Math.min(minn, n);
            maxx = Math.max(maxx, n);
            chk[n] = true;
        }

        List<Integer> ret = new ArrayList<>();
        for (int i=minn+1; i<maxx; i++) {
            if (!chk[i]) {
                ret.add(i);
            }
        }

        return ret;
    }
}
