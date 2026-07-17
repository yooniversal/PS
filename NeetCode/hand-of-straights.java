class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        Arrays.sort(hand);

        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int c : hand) {
            cntMap.put(c, cntMap.getOrDefault(c, 0) + 1);
        }

        int[] cards = new int[cntMap.size()];
        int[] values = new int[cntMap.size()];
        int iter = 0;
        int sum = 0;
        for (Map.Entry<Integer, Integer> entry : cntMap.entrySet()) {
            cards[iter] = entry.getKey();
            values[iter++] = entry.getValue();
            sum += entry.getValue();
        }

        boolean finish = false;
        int startIndex = 0;
        while (!finish) {
            if (startIndex + groupSize > values.length) return false;

            int nextIndex = -1;
            int prev = -1;
            int v = values[startIndex];
            for (int i=startIndex; i<startIndex + groupSize; i++) {
                if (prev != -1 && cards[i] - prev != 1) return false;
                prev = cards[i];
                values[i] -= v;
                sum -= v;

                if (values[i] < 0 || sum < 0) return false;

                if (nextIndex == -1 && values[i] > 0) nextIndex = i;
                if (i == values.length-1 && sum == 0) finish = true;
            }

            startIndex = nextIndex != -1 ? nextIndex : startIndex + groupSize;
        }

        return true;
    }
}
