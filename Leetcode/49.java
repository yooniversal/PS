class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            String sortedStr = sort(s);
            List<String> v = map.getOrDefault(sortedStr, new ArrayList<>());
            v.add(s);
            map.put(sortedStr, v);
        }

        List<List<String>> ret = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            ret.add(entry.getValue());
        }

        return ret;
    }

    private String sort(String str) {
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}
