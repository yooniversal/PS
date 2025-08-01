class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ret = new ArrayList<>();

        for (int r=1; r<=numRows; r++) {
            List<Integer> tmp = new ArrayList<>();
            for (int c=0; c<r; c++) {
                if (c == 0 || c == r-1) {
                    tmp.add(1);
                } else {
                    List<Integer> beforeRow = ret.get(ret.size()-1);
                    tmp.add(beforeRow.get(c-1) + beforeRow.get(c));
                }
            }
            ret.add(tmp);
        }

        return ret;
    }
}