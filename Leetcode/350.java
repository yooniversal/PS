class Solution {

    boolean[] chk = new boolean[1005];

    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> ret = new ArrayList<>();

        if (nums1.length >= nums2.length) {
            getIntersectionArray(nums1, nums2, ret);
        } else {
            getIntersectionArray(nums2, nums1, ret);
        }

        return ret.stream().mapToInt(Integer::intValue).toArray();
    }

    void getIntersectionArray(int[] nums1, int[] nums2, List<Integer> ret) {
        for (int i=0; i<nums1.length; i++) {
            for (int j=0; j<nums2.length; j++) {
                if (chk[j] || nums1[i] != nums2[j]) continue;
                chk[j] = true;
                ret.add(nums2[j]);
                break;
            }
        }
    }
}