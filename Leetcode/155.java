class MinStack {

    Stack<Integer> stack;
    Stack<Integer> minStack;
    Map<Integer, Integer> cntMap;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
        cntMap = new HashMap<>();
    }
    
    public void push(int value) {
        stack.push(value);
        int prevCnt = cntMap.getOrDefault(value, 0);
        cntMap.put(value, prevCnt + 1);

        if (minStack.isEmpty()) {
            minStack.push(value);
        } else if (minStack.peek() > value) {
            minStack.push(value);
        }
    }
    
    public void pop() {
        int target = stack.peek();

        stack.pop();
        int prevCnt = cntMap.getOrDefault(target, 0);
        cntMap.put(target, prevCnt - 1);

        if (prevCnt == 1 && target == minStack.peek()) {
            minStack.pop();
        }
    }
    
    public int top() {
        return stack.peek();   
    }
    
    public int getMin() {
        return minStack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
