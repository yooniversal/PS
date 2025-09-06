class Solution {
    public int lengthOfLastWord(String s) {
        String[] inputs = s.trim().split(" ");
        return inputs[inputs.length-1].length();
    }
}