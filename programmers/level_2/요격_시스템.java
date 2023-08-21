import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        
        Arrays.sort(targets, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]) {
                    return a[0] < b[0] ? -1 : 1;
                }
                return a[1] < b[1] ? 1 : -1;
            }
        });
        
        int end = targets[0][1];
        int cnt = 0;
        for(int[] arr : targets) {
            if(arr[0] < end) {
                cnt++;
                end = Math.min(end, arr[1]);
                continue;
            }
            
            answer++;
            cnt = 1;
            end = arr[1];
        }
        
        answer++;
        
        return answer;
    }
}