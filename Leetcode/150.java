class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for (String token : tokens) {
            if (!token.equals("+") 
                    && !token.equals("-")
                    && !token.equals("*") 
                    && !token.equals("/")) {
                stack.push(Integer.parseInt(token));
                continue;
            }

            int right = stack.pop();
            int left = stack.pop();

            switch (token) {
                case "+" -> stack.push(left + right);
                case "-" -> stack.push(left - right);
                case "*" -> stack.push(left * right);
                case "/" -> stack.push(left / right);
            }
        }

        return stack.pop();
    }
}
