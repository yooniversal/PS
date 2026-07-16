class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> arr = new ArrayList<>();

        for (int n : nums) {
            int index = lowerBound(arr, n);
            if (index >= arr.size()) arr.add(n);
            else arr.set(index, n);
        }

        return arr.size();
    }

    public int lowerBound(List<Integer> arr, int v) {
        int ret = 1005;
        int l = 0, r = arr.size()-1;

        while (l <= r) {
            int m = (l+r) / 2;

            if (arr.get(m) == v) return m;
            if (arr.get(m) < v) {
                l = m+1;
            } else {
                ret = m;
                r = m-1;
            }
        }

        return ret;
    }
}
