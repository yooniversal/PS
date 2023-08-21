package programmers;

import java.util.*;

class Solution {
    
    static HashMap<String, Integer> rank = new HashMap<String, Integer>();
    
    public String[] solution(String[] players, String[] callings) {

        for(int i=0; i<players.length; ++i) {
            rank.put(players[i], i);
        }
        
        for(String call : callings) {
            int cur = rank.get(call);
            String other = players[cur-1];
            players[cur-1] = call;
            players[cur] = other;
            rank.put(call, cur-1);
            rank.put(other, cur);
        }
        
        return players;
    }
}
