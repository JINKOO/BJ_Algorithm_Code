package queue;

import java.util.LinkedList;
import java.util.Queue;

public class Solution01 {
	
	private final int TOTAL = 100;
	
	public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        //
        
        // 1. 남은 작업량 계산하기
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < progresses.length; i++) {
        	int remainWork = (TOTAL - progresses[i]) / speeds[i];
        	if ((TOTAL - progresses[i]) % speeds[i] != 0) {
        		remainWork++;
        	}
        	queue.add(remainWork);
        }
        
        // 2. 큐에 삽입
        LinkedList<Integer> result = new LinkedList<>();
        while(!queue.isEmpty()) {
        	
        	int curr = queue.poll();
        	int count = 1;
        	
        	while (!queue.isEmpty() && curr >= queue.peek()) {
        		queue.poll();
        		count++;
        	}
        	result.add(count);
        }
        
        for (Integer val : result)
        	System.out.print(val + " ");
        
        
        //
        return answer;
    }
	
	public static void main(String[] args) {
		
		Solution01 sol = new Solution01();
		
		int[] progresses = {93, 30, 55};
		int[] speeds = {1, 30, 5};
		
		sol.solution(progresses, speeds);
	}
}



















