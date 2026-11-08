class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> nSet = new HashSet<>();
        for (int n : nums) nSet.add(n);

        for (int i=k; i<=300; i+=k) {
            if (!nSet.contains(i)) {
                return i;
            }
        }

        return 1;
    }
}
