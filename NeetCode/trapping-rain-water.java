class Solution {
    public int trap(int[] height) {
        int lmax=height[0], rmax=height[height.length-1];
        int l=0, r=height.length-1;

        int ret = 0;
        while (l <= r) {
            if (height[l] <= height[r]) {
                ret += lmax - height[l];
                l++;
                if (l < height.length) lmax = Math.max(lmax, height[l]);
            } else {
                ret += rmax - height[r];
                r--;
                if (r >= 0) rmax = Math.max(rmax, height[r]);
            }
        }

        return ret;
    }
}
