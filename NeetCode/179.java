class Solution {
    public String largestNumber(int[] nums) {
        String ret = Arrays.stream(nums)
            .mapToObj(String::valueOf)
            .sorted((s1, s2) -> (s2 + s1).compareTo(s1 + s2))
            .collect(Collectors.joining());

        if (ret.charAt(0) == '0') return "0";

        return ret;
    }
}
