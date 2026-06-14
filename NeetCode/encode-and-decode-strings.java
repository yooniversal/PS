class Solution {
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<strs.size(); i++) {
            if (strs.get(i).length() > 0) sb.append(strs.get(i));
            else sb.append("ㅂ");
            if (i < strs.size()-1) sb.append("ㅋ");
        }
        return sb.toString();
    }

    public List<String> decode(String str) {
        if (str == null || str.length() == 0) return List.of();
        String[] strs = str.split("ㅋ");
        List<String> tmp = new ArrayList<>(Arrays.asList(strs));

        List<String> ret = new ArrayList<>();
        for (String cur : tmp) {
            if (cur.equals("ㅂ")) ret.add("");
            else ret.add(cur);
        }

        return ret;
    }
}
