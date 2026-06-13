class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> cntMap = new HashMap<>();

        for (int n : nums) {
            cntMap.put(n, cntMap.getOrDefault(n, 0) + 1);
        }

        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(cntMap.entrySet());
        Collections.sort(entryList, (a, b) -> b.getValue() - a.getValue()); // desc

        return cntMap.entrySet().stream()
            .sorted(Map.Entry.<Integer, Integer>comparingByValue().reversed())
            .limit(k)
            .mapToInt(Map.Entry::getKey)
            .toArray();
    }
}
