class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] a = getCntList(word1);
        int[] b = getCntList(word2);

        for (int i=0; i<26; i++) {
            if (a[i] > 0 && b[i] == 0) return false;
            if (b[i] > 0 && a[i] == 0) return false;
        }

        List<Integer> aList = new ArrayList<>();
        List<Integer> bList = new ArrayList<>();

        for (int i=0; i<26; i++) {
            if (a[i] > 0) {
                aList.add(a[i]);
            }
        }
        aList.sort(null);

        for (int i=0; i<26; i++) {
            if (b[i] > 0) {
                bList.add(b[i]);
            }
        }
        bList.sort(null);

        if (aList.size() != bList.size()) return false;

        return aList.equals(bList);
    }

    private int[] getCntList(String w) {
        int[] cnt = new int[26];

        for (int i=0; i<w.length(); i++) {
            cnt[(int)(w.charAt(i) - 'a')]++;
        }

        return cnt;
    }
}
