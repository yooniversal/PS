import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> visited = new HashSet<>(Arrays.asList(deadends));
        if (visited.contains("0000")) return -1;

        Queue<State> queue = new ArrayDeque<>();
        queue.add(new State("0000", 0));
        visited.add("0000");

        while (!queue.isEmpty()) {
            State cur = queue.poll();

            if (cur.lock.equals(target)) {
                return cur.step;
            }

            for (String next : getNextStates(cur.lock)) {
                if (visited.contains(next)) continue;

                visited.add(next);
                queue.add(new State(next, cur.step + 1));
            }
        }

        return -1;
    }

    private List<String> getNextStates(String s) {
        List<String> nextStates = new ArrayList<>(8);
        char[] chars = s.toCharArray();

        for (int i=0; i<4; i++) {
            char original = chars[i];

            // 앞으로 돌리기 (+1)
            chars[i] = (original == '9') ? '0' : (char)(original + 1);
            nextStates.add(new String(chars));

            // 뒤로 돌리기 (-1)
            chars[i] = (original == '0') ? '9' : (char)(original - 1);
            nextStates.add(new String(chars));

            chars[i] = original;
        }

        return nextStates;
    }

    class State {
        String lock;
        int step;

        State(String lock, int step) {
            this.lock = lock;
            this.step = step;
        }
    }
}
