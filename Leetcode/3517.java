class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        int halfLen = n / 2;

        // 절반만 가져와서 a-z 정렬
        char[] half = s.substring(0, halfLen).toCharArray();
        Arrays.sort(half);

        String front = new String(half);
        
        // 뒷면 = 앞 절반 뒤집기
        String back = new StringBuilder(front).reverse().toString();

        // 짝홀수 구분
        if (n % 2 == 0) {
            return front + back;
        } else {
            return front + s.charAt(halfLen) + back;
        }
    }
}
