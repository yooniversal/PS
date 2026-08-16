class Solution {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> cntMap = new HashMap<>();
        int maxValue = 0;
        for (char t : tasks) {
            int cnt = cntMap.getOrDefault(t, 0);
            cntMap.put(t, cnt+1);
            maxValue = Math.max(maxValue, cnt+1);
        }

        int maxKind = 0;
        int elseCnt = 0;
        for (Map.Entry<Character, Integer> entry : cntMap.entrySet()) {
            int cnt = entry.getValue();
            if (cnt == maxValue) maxKind++;
            else elseCnt += cnt;
        }

        int ret = (maxValue - 1) * n + maxValue + maxKind - 1;
        int remainCnt = (maxValue - 1) * (n - maxKind + 1);
        if (elseCnt <= remainCnt) return ret;
        
        ret += elseCnt - remainCnt;
        return ret;
    }
}
