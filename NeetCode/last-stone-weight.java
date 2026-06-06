class Solution {
    public int lastStoneWeight(int[] stones) {
        while (stones.length > 1) {
            stones = process(stones);
        }

        return stones.length > 0 ? stones[0] : 0;
    }

    public int[] process(int[] stones) {
        List<Integer> sortedStones = Arrays.stream(stones)
            .sorted()
            .boxed()
            .collect(Collectors.toList());
        
        int one = sortedStones.get(sortedStones.size()-1);
        int two = sortedStones.get(sortedStones.size()-2);
        sortedStones.remove(sortedStones.size()-1);
        sortedStones.remove(sortedStones.size()-1);

        int diff = one - two;
        if (diff > 0) sortedStones.add(diff);

        return sortedStones.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}
