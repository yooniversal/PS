class MinStack {

    private int minValue;
    private List<Integer> arr, minArr;

    public MinStack() {
        this.minValue = Integer.MAX_VALUE;
        this.arr = new ArrayList<>();
        this.minArr = new ArrayList<>();
    }
    
    public void push(int val) {
        arr.add(val);

        if (minValue > val) minValue = val;
        minArr.add(minValue);
    }
    
    public void pop() {
        arr.remove(arr.size() - 1);
        minArr.remove(minArr.size() - 1);
        if (!minArr.isEmpty()) minValue = minArr.get(minArr.size() - 1);
        else minValue = Integer.MAX_VALUE;
    }
    
    public int top() {
        return arr.get(arr.size() - 1);
    }
    
    public int getMin() {
        return minValue;
    }
}
