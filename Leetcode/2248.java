class Solution {

    boolean chk[][] = new boolean[1005][1005];

    public List<Integer> intersection(int[][] nums) {
        List<Integer> ret = new ArrayList<>();
        Set<Integer> numberSet = new HashSet<Integer>();

        for (int i=0; i<nums.length; i++) {
            for (int num : nums[i]) {
                numberSet.add(num);
                chk[i][num] = true;
            }
        }

        Iterator<Integer> iter = numberSet.iterator();
        while (iter.hasNext()) {
            int num = iter.next();

            boolean flag = true;
            for (int i=0; i<nums.length; i++) {
                if (!chk[i][num]) {
                    flag = false;
                    break;
                }
            }

            if (flag) ret.add(num);
        }

        Collections.sort(ret);

        return ret;
    }
}