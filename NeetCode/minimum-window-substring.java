class Solution {
    public String minWindow(String s, String t) {
        String ret = "";

        Map<Character, Boolean> tMap = new HashMap<>();
        Map<Character, Integer> chk = new HashMap<>();
        Map<Character, Integer> cnt = new HashMap<>();

        int disjointSize = 0;
        for (int i=0; i<t.length(); i++) {
            if (tMap.get(t.charAt(i)) == null) {
                tMap.put(t.charAt(i), true);
                chk.put(t.charAt(i), 0);
                disjointSize++;
            }

            cnt.put(t.charAt(i), cnt.getOrDefault(t.charAt(i), 0) + 1);
        }

        List<Integer> disjointList = new ArrayList<>();
        for (int i=0; i<s.length(); i++) {
            if (tMap.getOrDefault(s.charAt(i), false)) {
                disjointList.add(i);
            }
        }

        if (disjointList.isEmpty()) return ret;

        int cur = 0;
        int start = 0, end = 0;

        chk.put(s.charAt(disjointList.get(0)), 1);
        if (chk.get(s.charAt(disjointList.get(0))) == cnt.get(s.charAt(disjointList.get(0)))) cur++;

        for (int i=0; i<disjointList.size(); i++) {
            char v = s.charAt(disjointList.get(i));

            while (cur == disjointSize) {
                String target = s.substring(disjointList.get(start), disjointList.get(end)+1);
                if (ret.length() == 0) ret = target;
                else if (ret.length() > target.length()) ret = target;

                chk.put(
                    s.charAt(disjointList.get(start)),
                    chk.get(s.charAt(disjointList.get(start))) - 1
                );
                if (chk.get(s.charAt(disjointList.get(start))) < cnt.get(s.charAt(disjointList.get(start)))) cur--;

                start++;
            }

            end++;
            if (end < disjointList.size()) {
                chk.put(
                    s.charAt(disjointList.get(end)),
                    chk.get(s.charAt(disjointList.get(end))) + 1
                );

                if (chk.get(s.charAt(disjointList.get(end))) == cnt.get(s.charAt(disjointList.get(end)))) cur++;
            }
        }

        return ret;
    }
}
