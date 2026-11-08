class SnapshotArray {

    int curSnapId;
    int len;
    List<List<int[]>> arr;

    public SnapshotArray(int length) {
        arr = new ArrayList<>();
        len = length;

        for (int i=0; i<len; i++) {
            List<int[]> history = new ArrayList<>();
            history.add(new int[]{0, 0});
            arr.add(history);
        }
    }
    
    public void set(int index, int val) {
        List<int[]> history = arr.get(index);
        int[] arr = history.get(history.size() - 1);

        if (arr[0] == curSnapId) {
            arr[1] = val;
        } else {
            history.add(new int[]{curSnapId, val});
        }
    }
    
    public int snap() {
        return updateSnapId();
    }
    
    public int get(int index, int snap_id) {
        List<int[]> history = arr.get(index);
        return history.get(binarySearch(history, snap_id))[1];
    }

    private int updateSnapId() {
        return curSnapId++;
    }

    private int binarySearch(List<int[]> history, int v) {
        int l=0, r=history.size()-1;
        int m = (l+r) / 2;
        int ret = 0;

        while (l <= r) {
            m = (l+r) / 2;

            if (history.get(m)[0] <= v) {
                if (history.get(m)[0] == v) {
                    return m;
                }
                ret = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return ret;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
