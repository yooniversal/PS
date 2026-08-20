class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();

        for (int n : nums) {
            if (arr1.size() == 0) {
                arr1.add(n);
            } else if (arr2.size() == 0) {
                arr2.add(n);
            } else {
                if (arr1.get(arr1.size()-1) > arr2.get(arr2.size()-1)) {
                    arr1.add(n);
                } else {
                    arr2.add(n);
                }
            }
        }

        int[] ret = new int[arr1.size() + arr2.size()];
        for (int i=0; i<arr1.size(); i++) {
            ret[i] = arr1.get(i);
        }
        for (int i=0; i<arr2.size(); i++) {
            ret[arr1.size() + i] = arr2.get(i);
        }

        return ret;
    }
}
