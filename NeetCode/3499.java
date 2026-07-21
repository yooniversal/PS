class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        List<Integer> zeros = new ArrayList<>();
        List<Integer> zeroIndex = new ArrayList<>();
        List<Integer> ones = new ArrayList<>();

        int zeroCnt = 0, oneCnt = 0;
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if (c == '0') {
                zeroCnt++;

                if (zeroIndex.isEmpty() || oneCnt > 0) zeroIndex.add(i);
                if (!zeros.isEmpty() && oneCnt > 0) ones.add(oneCnt);
                oneCnt = 0;

                if (i == s.length()-1 && zeroCnt > 0) {
                    zeros.add(zeroCnt);
                }
            } else if (zeroCnt > 0) {
                zeros.add(zeroCnt);
                zeroCnt = 0;

                oneCnt++;
            }
        }

        if (zeros.size() <= 1) {
            int oneCount = 0;
            for (char c : s.toCharArray()) {
                if (c == '1') oneCount++;
            }

            return oneCount;
        }
        
        int maxIndex = 0;
        int maxx = zeros.get(0) + zeros.get(1) + ones.get(0);
        for (int i=0; i<ones.size(); i++) {
            if (maxx < zeros.get(i) + zeros.get(i+1) + ones.get(i)) {
                maxx = zeros.get(i) + zeros.get(i+1) + ones.get(i);
                maxIndex = i;
            }
        }

        char[] chars = s.toCharArray();
        int len = zeroIndex.size() > maxIndex+2 ? zeroIndex.get(maxIndex+2) : s.length();
        for (int i=zeroIndex.get(maxIndex); i<len; i++) {
            chars[i] = '1';
        }

        int ret = 0;
        for (char c : chars) {
            if (c == '1') ret++;
        }

        return ret;
    }
}
