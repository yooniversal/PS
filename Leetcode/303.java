class NumArray {

    private int[] prefixSum;

    public NumArray(int[] nums) {
        prefixSum = new int[nums.length];
        prefixSum[0] = nums[0];

        for (int i=1; i<nums.length; i++) prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    public int sumRange(int left, int right) {
        int sum = prefixSum[right];
        if (left > 0) sum -= prefixSum[left-1];
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
