class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if (p.length() > s.length()) return Collections.emptyList();

        int[][] cnt = new int[s.length()+1][26];
        int[] currentCnt = new int[26];
        for (int i=s.length()-1; i>=0; i--) {
            currentCnt[(int)(s.charAt(i) - 'a')]++;

            for (int j=0; j<26; j++) cnt[i][j] = currentCnt[j];
        }

        int[] pCnt = new int[26];
        for (int i=0; i<p.length(); i++) {
            pCnt[(int)(p.charAt(i) - 'a')]++;
        }

        List<Integer> ret = new ArrayList<>();
        for (int i=0; i<=s.length()-p.length(); i++) {

            boolean flag = true;
            for (int j=0; j<26; j++) {
                if (pCnt[j] != cnt[i][j] - cnt[i+p.length()][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) ret.add(i);
        }

        return ret;
    }
}
