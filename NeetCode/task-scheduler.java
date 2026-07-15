class Solution {
    public int leastInterval(char[] tasks, int n) {
        int maxValue = 0;
        Map<Character, Integer> taskMap = new HashMap<>();
        for (char t : tasks) {
            taskMap.put(t, taskMap.getOrDefault(t, 0) + 1);
            maxValue = Math.max(maxValue, taskMap.get(t));
        }

        int maxKind = 0;
        for (Map.Entry<Character, Integer> entry : taskMap.entrySet()) {
            int cnt = entry.getValue();
            if (cnt == maxValue) maxKind++;
        }

        int ret = maxValue + (maxValue-1) * n + (maxKind-1);
        ret = Math.max(ret, tasks.length);
        return ret;
    }
}
