package stack;

import java.util.Stack;

public class Solution01 {
	
	boolean solution(String s) {
	    boolean answer = true;
	    
	    // 1. stk선언
	    Stack<Character> stk = new Stack<>();
	    
	    
	    // 2. stack연산
	    for (int i = 0; i < s.length(); i++) {
	    	char c = s.charAt(i);
	    	
	    	if (!stk.isEmpty() && ((stk.peek() == '(' && c == ')') || (stk.peek() == '{' && c == '}') || stk.peek() == '[' && c== ']')) {
	    		
	    		stk.pop();
	    		continue;
	    	}
	    	
	    	stk.add(c);
	    }
	    
	    // 3. stack이 비어있지 않는다면, false를 return한다.
	    if (!stk.isEmpty())
	    	answer = false;
	    
	    return answer;
	}
	
	public static void main(String[] args) {
		
		Solution01 sol = new Solution01();
		
		System.out.println(sol.solution("{{}}"));     // true
		System.out.println(sol.solution("({})[]"));   // true
		System.out.println(sol.solution("([())]"));   // false
	}
}










