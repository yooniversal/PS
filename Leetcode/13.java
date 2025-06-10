class Solution {
    public int romanToInt(String s) {
        int ret = 0;

        for (int i=0; i<s.length(); i++) {
            char cur = s.charAt(i);
            if (i < s.length()-1 && (cur == 'I' || cur == 'X' || cur == 'C')) {
                char nextChar = s.charAt(i+1);

                if (
                    (cur == 'I' && (nextChar == 'V' || nextChar == 'X'))
                    || (cur == 'X' && (nextChar == 'L' || nextChar == 'C'))
                    || (cur == 'C' && (nextChar == 'D' || nextChar == 'M'))
                ) {
                    ret += romanCharToInt(nextChar) - romanCharToInt(cur);
                    i++;
                } else {
                    ret += romanCharToInt(cur);
                }

            } else {
                ret += romanCharToInt(cur);
            }
        }

        return ret;
    }

    public int romanCharToInt(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;
    }
}