class Solution {
    char[][] letterByNumber = {
        {}, {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };

    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<>();

        f(ret, digits, 0, "");

        return ret;
    }

    public void f(List<String> ret, String digits, int cur, String letters) {
        if (digits.length() == 0) return;
        if (digits.length() <= cur) {
            ret.add(letters);
            return;
        }
        
        int currentNumber = digits.charAt(cur) - '0';
        for (int i=0; i<letterByNumber[currentNumber].length; i++) {
            f(ret, digits, cur+1, letters + letterByNumber[currentNumber][i]);
        }
    }
}