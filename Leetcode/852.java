class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l = 1, r = arr.length-2;

        while (l <= r) {
            int mid = (l + r) / 2;

            // peak
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            }

            if (arr[mid] < arr[mid+1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }
}
