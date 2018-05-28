import java.util.*;

public class MinStack {
	Deque<Integer> stack, minStack;
	
    /** initialize your data structure here. */
    public MinStack() {
        stack = new ArrayDeque<Integer>();
        minStack = new ArrayDeque<Integer>();
    }
    
    public void push(int x) {
        stack.addLast(x);
        minStack.addLast(Math.min(x, (minStack.size() > 0 ? minStack.getLast() : Integer.MAX_VALUE)));
    }
    
    public void pop() {
        stack.removeLast();
        minStack.removeLast();
    }
    
    public int top() {
        return stack.getLast();
    }
    
    public int getMin() {
        return minStack.getLast();
    }
    
    public static void main(String argc[]) {
    	MinStack minStack = new MinStack();
    	minStack.push(-2);
    	minStack.push(0);
    	minStack.push(-3);
    	System.err.println(minStack.getMin());   //--> Returns -3.
    	minStack.pop();
    	System.err.println(minStack.top());      //--> Returns 0.
    	System.err.println(minStack.getMin());   //--> Returns -2.
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */