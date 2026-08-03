class Solution {
    public int maxArea(int[] heights) {
        int ret = 0;

        for (int i=0, j=heights.length-1; i<j;) {
            ret = Math.max(ret, (j-i) * Math.min(heights[i], heights[j]));
            if (heights[i] <= heights[j]) i++;
            else j--;
        }

        return ret;
    }
}
