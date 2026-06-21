class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();

        Map<Integer, List<List<Integer>>> map = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            for (int j=i+1; j<nums.length; j++) {
                List<List<Integer>> v = map.getOrDefault(nums[i] + nums[j], new ArrayList<>());
                v.add(List.of(i, j));
                map.put(nums[i] + nums[j], v);
            }
        }

        Set<List<Integer>> set = new HashSet<>();
        for (int k=0; k<nums.length; k++) {
            List<List<Integer>> llist = map.get(-nums[k]);
            if (llist == null) continue;

            for (int llistIndex=0; llistIndex<llist.size(); llistIndex++) {
                List<Integer> list = llist.get(llistIndex);
                if (list.contains(k)) continue;

                List<Integer> tmp = new ArrayList<>();
                tmp.add(nums[list.get(0)]);
                tmp.add(nums[list.get(1)]);
                tmp.add(nums[k]);
                Collections.sort(tmp);

                if (set.contains(tmp)) continue;
                set.add(tmp);
                ret.add(tmp);
            }
        }

        return ret;
    }
}
