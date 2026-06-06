class KthLargest {

    private List<Integer> arr;
    private int k;

    public KthLargest(int k, int[] nums) {
        this.arr = new ArrayList<>();
        Arrays.stream(nums).forEach(n -> {
            arr.add(n);
        });

        this.k = k;
    }
    
    public int add(int val) {
        arr.add(val);

        List<Integer> sortedArr = arr.stream()
            .sorted(Comparator.reverseOrder())
            .toList();
        arr = new ArrayList<>(sortedArr);

        return arr.get(k-1);
    }
}
