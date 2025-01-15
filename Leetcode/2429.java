class Solution {

    public String toBitwise(int num) {
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            if (num % 2 == 1) sb.append("1");
            else sb.append("0");
            num /= 2;
        }
        sb.reverse();
        
        while (sb.length() < 30) {
            sb.insert(0, "0");
        }
        return sb.toString();
    }

    public int minimizeXor(int num1, int num2) {
        String str1 = toBitwise(num1);
        String str2 = toBitwise(num2);

        int oneCnt = 0;
        for (int i=0; i<str2.length(); i++) {
            if (str2.charAt(i) == '1') oneCnt++;
        }

        boolean[] checked = new boolean[str1.length()];
        for (int i=0; i<str1.length(); i++) {
            if (oneCnt > 0 && str1.charAt(i) == '1') {
                oneCnt--;
                checked[i] = true;
            }
        }

        if (oneCnt > 0) {
            for (int i=str1.length()-1; i>=0 && oneCnt > 0; i--) {
                if (checked[i]) continue;
                checked[i] = true;
                oneCnt--;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i=0; i<checked.length; i++) {
            if (checked[i]) sb.append('1');
            else sb.append('0');
        }

        String retStr = sb.toString();
        int ret = 0;
        for (int i=retStr.length()-1, j=0; i>=0; i--, j++) {
            if (retStr.charAt(i) == '1') ret += Math.pow(2, j);
        }
        
        return ret;
    }
}