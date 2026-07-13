class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ret = new ArrayList<>();
        String s = "123456789";
        
        int target = low;
        int leftWindow = 0;
        while (target > 0) {
            leftWindow++;
            target /= 10;
        }

        target = high;
        int rightWindow = 0;
        while (target > 0) {
            rightWindow++;
            target /= 10;
        }

        for (int window=leftWindow; window<=rightWindow ; window++) {
            for (int i=0; i<9 && i+window-1 < 9; i++) {
                int v = Integer.valueOf(s.substring(i, i+window));
                if (low <= v && v <= high) {
                    ret.add(v);
                }
            }
        }
        
        return ret;
    }
}
