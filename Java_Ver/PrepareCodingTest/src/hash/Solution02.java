package hash;

import java.util.HashMap;

public class Solution02 {
	
	public String solution(String[] participant, String[] completion) {
		
		String answer = "";
		
		HashMap<String, Integer> map = new HashMap<>();
		
		// 1. 완주자를 모두 map에 삽입한다.
		for (String name : completion) {
			if (!map.containsKey(name))
				map.put(name, 1);
			else
				map.put(name, map.get(name) + 1);
		}
		
		// 2.참가자목록에서 없다면, 바로 리턴.
		for (String name : participant) {
			if (!map.containsKey(name)) {
				return name;
			}
			
			// 참가자가 있다면, -1을 한다.
			map.put(name, map.get(name) - 1);
		}
		
		
		// 3.동명이인 처리
		for (String name : participant) {
			if (map.get(name) < 0) {
				return name;
			}
		}
		
		return answer;
		
	}
	
	public static void main(String[] args) {
		
		Solution02 sol = new Solution02();
		
		
		String[] participant = {"marina", "josipa", "nikola", "vinko", "filipa"}; 
		String[] completion = {"josipa", "filipa", "marina", "nikola"};
		
		System.out.println(sol.solution(participant, completion));
	}
}
