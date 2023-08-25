class Solution {
    public int[] solution(int brown, int yellow) {
        int sum = brown + yellow;
        for(int b=3; ; ++b) {
            if(sum % b != 0) continue;
            
            int a = sum / b;
            if((a-2) * (b-2) != yellow) continue;
            int[] answer = new int[]{a, b};
            return answer;
        }
    }
}