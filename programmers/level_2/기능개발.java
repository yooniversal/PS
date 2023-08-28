import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        int[] rem = new int[progresses.length];
        for (int i=0; i<rem.length; ++i) {
            int v = (100 - progresses[i]) / speeds[i];
            if ((100 - progresses[i]) % speeds[i] != 0) ++v;
            
            rem[i] = v;
        }
        
        int cnt = 1;
        int prev = rem[0];
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i=1; i<rem.length; ++i) {
            if (rem[i] <= prev) {
                ++cnt;
                continue;
            }
            
            ans.add(cnt);
            cnt = 1; prev = rem[i];
        }
        
        ans.add(cnt);
        
        answer = new int[ans.size()];
        for (int i=0; i<ans.size(); ++i) {
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
}