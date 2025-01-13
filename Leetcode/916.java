class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ret = new ArrayList<>();

        int[] targetCnt = new int[26];
        for (int i=0; i<words2.length; i++) {
            int[] cnt = new int[26];
            for (int j=0; j<words2[i].length(); j++) {
                cnt[words2[i].charAt(j) - 'a']++;    
            }
            
            for (int j=0; j<26; j++) {
                targetCnt[j] = Math.max(targetCnt[j], cnt[j]);
            }
        }

        for (int i=0; i<words1.length; i++) {
            if (isUnique(words1[i], targetCnt)) ret.add(words1[i]);
        }

        return ret;
    }

    public boolean isUnique(String word, int[] targetCnt) {
        int[] wordCnt = new int[26];
        for (int i=0; i<word.length(); i++) {
            wordCnt[word.charAt(i) - 'a']++;
        }

        for (int i=0; i<26; i++) {
            if (wordCnt[i] < targetCnt[i]) return false;
        }

        return true;
    }
}