package queue;

import java.util.PriorityQueue;

// Priority Queue
public class Solution02 {
	
	private final int MULTIPLE_VALUE = 2;
	
	public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < scoville.length; i++)
        	pq.add(scoville[i]);
        
        while (!pq.isEmpty() && pq.peek() < K) {
        	// 첫번째거 꺼내고,
        	int curr = pq.poll();
        	
        	// 첫번째거 꺼냈는데 비었을 경
        	if (pq.isEmpty()) {
        		return -1;
        	}
        	
        	// 스코빌 지수 계산 후 다시 삽입.
        	pq.add(curr * pq.poll() * MULTIPLE_VALUE);
        	
        	answer++;
        }
        
        return answer;
	}
	
	public static void main(String[] args) {
		
		Solution02 sol2 = new Solution02();
		
		int[] scoville = {1, 2, 3, 9, 10, 12};
		int K = 7;
		
		System.err.println(sol2.solution(scoville, K));
	}
}
