class Solution {

    private static List<List<String>> ret;

    public List<List<String>> partition(String s) {
        ret = new ArrayList<>();
        for (int sz=1; sz<=s.length(); sz++) {
            doPalindrome(s, 0, sz, new ArrayList<>());
        }
        return ret;
    }

    public void doPalindrome(String s, int cur, int sz, List<String> rem) {
        if (cur >= s.length()) {
            ret.add(new ArrayList<>(rem));
            return;
        }

        for (int nextSz=1; nextSz<=s.length()-cur-sz+1; nextSz++) {
            String substr = s.substring(cur, cur+sz);
            if (!isPalindrome(substr)) continue;
            rem.add(substr);
            doPalindrome(s, cur+sz, nextSz, rem);
            rem.remove(rem.size()-1);
        }
    }

    public boolean isPalindrome(String s) {
        for (int i=0, j=s.length()-1; i<=j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }
}
