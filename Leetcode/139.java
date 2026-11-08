class Solution {

    private Map<Character, List<String>> words;
    private boolean[] chk;
    private boolean ret;

    public boolean wordBreak(String s, List<String> wordDict) {
        ret = false;
        chk = new boolean[s.length()];

        words = new HashMap<>();
        for (String word : wordDict) {
            List<String> v = words.getOrDefault(word.charAt(0), new ArrayList<>());
            v.add(word);
            words.put(word.charAt(0), v);
        }

        search(s, 0);

        return ret;
    }

    private void search(String s, int start) {
        if (ret || start >= s.length()) {
            ret = true;
            return;
        }
        if (chk[start]) return;

        for (String w : words.getOrDefault(s.charAt(start), Collections.emptyList())) {
            if (ret) return;
            if (!canPass(s, start, w)) continue;
            search(s, start + w.length());
        }

        chk[start] = true;
    }

    private boolean canPass(String s, int start, String word) {
        if (start + word.length()-1 >= s.length()) return false;

        for (int i=start, j=0; j<word.length(); i++, j++) {
            if (s.charAt(i) != word.charAt(j)) return false;
        }

        return true;
    }
}
