class Solution {

    private boolean finish;
    private boolean[] searched;

    public boolean wordBreak(String s, List<String> wordDict) {
        finish = false;
        searched = new boolean[205];

        Map<Character, List<String>> startWordMap = new HashMap<>();
        for (String w : wordDict) {
            List<String> rem = startWordMap.getOrDefault(w.charAt(0), new ArrayList<>());
            rem.add(w);
            startWordMap.put(w.charAt(0), rem);
        }

        checkBreak(startWordMap, s, 0);
        return finish;
    }

    public void checkBreak(Map<Character, List<String>> startWordMap, String s, int cur) {
        if (cur >= s.length() || finish) {
            finish = true;
            return;
        }
        if (searched[cur]) return;
        searched[cur] = true;

        List<String> startWords = startWordMap.getOrDefault(
            s.charAt(cur), 
            Collections.emptyList()
        );
            
        for (String w : startWords) {
            if (finish) break;

            if (canStart(s, cur, w)) {
                checkBreak(startWordMap, s, cur + w.length());
            }
        }
    }

    public boolean canStart(String s, int cur, String target) {
        if (s.length() - cur < target.length()) return false;

        for (int i=cur, j=0; i<s.length() && j<target.length(); i++, j++) {
            if (s.charAt(i) != target.charAt(j)) return false;
        }

        return true;
    }
}
