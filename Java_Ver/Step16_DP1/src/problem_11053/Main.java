/*
 *  #. [ 백준_11053번 가장 긴 증가하는 부분 수열 ] Silver II
 *  
 *  #. 문제
 *     수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 *     예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 *     
 *  #. 입력
 *     - 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
 *     - 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
 *     
 *  #. 출력
 *     첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 *     
 *  #. 예제 입력 1 
 *     6
 *     10 20 10 30 20 50
 *  #. 예제 출력 1 
 *     4
 */

package problem_11053;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private int n;
	private int[] cost;
	private int[] dp;
	
	public int solution() {
		int answer = 0;
		//
		dp[0] = 0;
		
		for(int i = 1; i <= n; i++) {
			int max_dp = dp[0];
			for(int j = 1; j < i; j++) {
				if(cost[i] > cost[j]) {
					if(max_dp < dp[j])
						max_dp = dp[j];
				}
			}
			dp[i] = max_dp + 1;
		}
		
		for(int i = 1; i <= n; i++) {
			if(answer < dp[i])
				answer = dp[i];
		}
		//
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		m.n = Integer.valueOf(input);
		m.cost = new int[m.n+1];
		m.dp = new int[m.n + 1];
		
		String input_cost = br.readLine();
		StringTokenizer stk = new StringTokenizer(input_cost, " ");
		
		int i = 1;
		while(stk.hasMoreTokens()) {
			m.cost[i++] = Integer.valueOf(stk.nextToken());
		}
		
		System.out.println(m.solution());
	}
}
