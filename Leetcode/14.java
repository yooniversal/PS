class Solution {
    public String longestCommonPrefix(String[] strs) {
        int ptr = 0;

        int minLength = 205;
        for (String str : strs) minLength = Math.min(minLength, str.length());
        
        while (ptr < minLength) {
            char firstChar = strs[0].charAt(ptr);
            boolean flag = false;

            for (String str : strs) {
                if (str.charAt(ptr) != firstChar) {
                    flag = true;
                    break;
                }
            }

            if (flag) break;
            ptr++;
        }

        if (ptr > 0) return strs[0].substring(0, ptr);
        return "";
    }
}