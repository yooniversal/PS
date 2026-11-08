class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> cnt = new HashMap<>();

        for (String w : words) {
            cnt.put(w, cnt.getOrDefault(w, 0) + 1);
        }

        Map<Integer, List<String>> wordsByCnt = new HashMap<>();

        for (Map.Entry<String, Integer> entry : cnt.entrySet()) {
            List<String> wordsOnKey = wordsByCnt.getOrDefault(entry.getValue(), new ArrayList<>());
            wordsOnKey.add(entry.getKey());
            wordsByCnt.put(entry.getValue(), wordsOnKey);
        }

        List<Integer> keys = new ArrayList<>(wordsByCnt.keySet());
        keys.sort(Collections.reverseOrder());

        List<String> ret = new ArrayList<>();
        for (int key : keys) {
            if (ret.size() == k) break;
            List<String> v = wordsByCnt.get(key);
            v.sort(null);
            
            for (String vv : v) {
                if (ret.size() == k) break;
                ret.add(vv);
            }
        }

        return ret;
    }
}
