class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        String ret = "";

        int cur = 0, retLength = 0;
        for (int l=0, r=0; r<s.length(); r++) {
            if (s.charAt(r) == '1') {
                cur++;

                if (cur == k) {
                    String target = s.substring(l, r+1);

                    if (retLength == 0) {
                        ret = target;
                        retLength = r-l+1;
                    } else if (retLength == r-l+1 && ret.compareTo(target) > 0) {
                        ret = target;
                        retLength = r-l+1;
                    } else if (retLength > r-l+1) {
                        ret = target;
                        retLength = r-l+1;
                    }

                    while (cur >= k) {
                        if (s.charAt(l) == '1') cur--;
                        l++;

                        if (cur == k) {
                            target = s.substring(l, r+1);

                            if (retLength == r-l+1 && ret.compareTo(target) > 0) {
                                ret = target;
                                retLength = r-l+1;
                            } else if (retLength > r-l+1) {
                                ret = target;
                                retLength = r-l+1;
                            }
                        }
                    }
                }
            }
        }

        return ret;
    }
}
