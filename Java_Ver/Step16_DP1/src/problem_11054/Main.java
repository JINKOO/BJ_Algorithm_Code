/*
 * https://www.acmicpc.net/problem/11054
 */
package problem_11054;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private int n;
	private int[] cost;
	private int[] dp;
	private int[] dpReverse;
	
	public int solution() {
		int answer = 0;
		//
		//1. 가장 긴 증가하는 수열 길이 찾기
		for(int i = 1; i <= n; i++) {
			int max_dp = 0;
			for(int j = 1; j < i; j++) {
				if(cost[i] > cost[j]) {
					if(max_dp < dp[j])
						max_dp = dp[j];
				}
			}
			dp[i] = max_dp + 1;
		}
		
		//2. 가장 긴 감소하는 수열 길이 찾기(역 방향으로 가장 긴 증가하는 수열 길이 찾기와 동일)
		for(int i = n; i >= 1; i--) {
			int max_dp = 0;
			for(int j = n; j > i; j--) {
				if(cost[i] > cost[j]) {
					if(max_dp < dpReverse[j])
						max_dp = dpReverse[j];
				}
			}
			dpReverse[i] = max_dp + 1;
		}
		
		for(int i = 1; i <= n; i++) {
			if(answer < dp[i] + dpReverse[i] - 1)
				answer = dp[i] + dpReverse[i] - 1;
		}
		
		//
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str_n = br.readLine();
		
		m.n = Integer.valueOf(str_n);
		m.cost = new int[m.n + 1];
		m.dp = new int[m.n + 1];
		m.dpReverse = new int[m.n + 1];
		
		String str_cost = br.readLine();
		StringTokenizer stk = new StringTokenizer(str_cost, " ");
		int i = 1;
		while(stk.hasMoreTokens()) {
			m.cost[i++] = Integer.valueOf(stk.nextToken());
		}
		
		System.out.println(m.solution());
	}
}
