class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ret = new ArrayList<>();

        List<String> sortedStrs = Arrays.stream(strs)
            .map(str -> {
                char[] chars = str.toCharArray();
                Arrays.sort(chars);
                return new String(chars);
            })
            .toList();

        Map<String, Integer> map = new HashMap<>();
        int anagramSize = 0;

        for (int i=0; i<sortedStrs.size(); i++) {
            String sortedStr = sortedStrs.get(i);

            if (map.containsKey(sortedStr)) {
                int anagramIndex = map.get(sortedStr);
                ret.get(anagramIndex).add(strs[i]);
            } else {
                map.put(sortedStr, anagramSize++);
                List<String> newAnagramList = new ArrayList<>(List.of(strs[i]));
                ret.add(newAnagramList);
            }
        }

        return ret;
    }
}
