package hash;

import java.util.HashMap;
import java.util.Set;

public class Solution01 {

	public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> map = new HashMap<>();
        
        for (int i = 0; i < clothes.length; i++) {
        	if (map.containsKey(clothes[i][1]))
        		map.put(clothes[i][1], map.get(clothes[i][1]) + 1);
        	else
        		map.put(clothes[i][1], 1);
        }
        
        Set<String> keySet = map.keySet();
        for (String key : keySet) {
        	answer *= (map.get(key) + 1);
        }
        
        answer -= 1;
        
        return answer;
	}
	
	public static void main(String[] args) {
		
		Solution01 sol = new Solution01();
		
		String[][] clothes = {
				{"yellowhat", "headgear"}, 
				{"bluesunglasses", "eyewear"}, 
				{"green_turban", "headgear"}
				};
		
		
		System.out.println(sol.solution(clothes));
	}
}
