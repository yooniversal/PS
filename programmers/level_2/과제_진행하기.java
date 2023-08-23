import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        
        for(String[] p : plans) {
            p[1] = Integer.toString(minutes(p[1]));
        }
        
        Arrays.sort(plans, new Comparator<String[]>() {
            @Override
            public int compare(String[] a, String[] b) {
                return Integer.parseInt(a[1]) - Integer.parseInt(b[1]);
            }
        });
        
        Stack<String[]> st = new Stack<>();
        st.push(plans[0]);
        int next = 1;
        int now = 0;
        ArrayList<String> ret = new ArrayList<>();
        
        while(!st.empty()) {
            String[] cur = st.peek(); st.pop();
            
            if(next >= plans.length) {
                // System.out.printf("cur:%s %s\n", cur[0], cur[1]);
                ret.add(cur[0]);
                continue;
            }
            
            int curStart = Integer.parseInt(cur[1]);
            int nextStart = Integer.parseInt(plans[next][1]);
            
            // System.out.printf("start: %s %d | %s %d\n", cur[0], curStart, plans[next][0], nextStart);
            
            if(nextStart - curStart < Integer.parseInt(cur[2])) {
                int remainTime = Integer.parseInt(cur[2]) - (nextStart - curStart);
                cur[1] = Integer.toString(nextStart);
                cur[2] = Integer.toString(remainTime);
                st.push(cur);
            } else {
                ret.add(cur[0]);
                
                if(!st.empty()) {
                    String[] top = st.peek(); st.pop();
                    top[1] = Integer.toString(curStart + Integer.parseInt(cur[2]));
                    st.push(top);
                    continue;
                }
            }
            
            st.push(plans[next++]);
        }
        
        
        for(int i=0; i<ret.size(); ++i) {
            answer[i] = ret.get(i);
        }
        
        return answer;
    }
    
    static void stackPush(Stack<String[]> st, String[] target) {
        Stack<String[]> tmp = new Stack<>();
        tmp.push(st.peek()); st.pop();
        while(!tmp.empty()) {
            String[] cur = tmp.peek(); tmp.pop();
            if(Integer.parseInt(cur[1]) < Integer.parseInt(target[1])) {
                st.push(cur);
                continue;
            }
        }
    }
    
    static int minutes(String time) {
        String[] hm = time.split(":");
        int hour = Integer.parseInt(hm[0]);
        int min = Integer.parseInt(hm[1]);
        return hour*60 + min;
    }
}