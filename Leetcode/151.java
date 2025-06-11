class Solution {
    public String reverseWords(String s) {
        String[] strings = s.trim().split(" ");
        
        StringBuilder sb = new StringBuilder();
        for (int i=strings.length-1; i>=0; i--) {
            if (strings[i].trim().isEmpty()) continue;
            sb.append(strings[i]);
            if (i > 0) sb.append(" ");
        }
        
        return sb.toString();
    }
}