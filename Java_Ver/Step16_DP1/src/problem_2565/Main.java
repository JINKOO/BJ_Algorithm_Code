/*
 * 
 *   https://www.acmicpc.net/problem/2565
 * 
 */

package problem_2565;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

class Line {
	int aLine;
	int bLine;
	
	Line(int aLine, int bLine) {
		this.aLine = aLine;
		this.bLine = bLine;
	}
}

public class Main {

	private int n;
	private int[] dp;
	private ArrayList<Line> list = new ArrayList<>();
	
	public int solution() {
		int answer = 0;
		int maxLine = 0;
		
		Collections.sort(list, new Comparator<Line>() {
			@Override
			public int compare(Line l1, Line l2) {
				return l1.aLine - l2.aLine;
			}
		});
		
		for(int i = 0; i < n; i++) {
			int max_dp = 0;
			for(int j = 0; j < i; j++) {
				if(list.get(i).bLine > list.get(j).bLine) {
					if(max_dp < dp[j])
						max_dp = dp[j];
				}
			}
			dp[i] = max_dp + 1;
		}
		
		for(int i = 0; i < n; i++) {
			if(maxLine < dp[i])
				maxLine = dp[i];
		}
		
		answer = n - maxLine;
		
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n_str = br.readLine();
		
		m.n = Integer.valueOf(n_str);
		m.dp = new int[m.n];
		
		for(int i = 0; i < m.n; i++) {
			String line = br.readLine();
			StringTokenizer stk = new StringTokenizer(line, " ");
			
			m.list.add(new Line(Integer.valueOf(stk.nextToken()), Integer.valueOf(stk.nextToken())));
		}
		
		System.out.println(m.solution());
	}
}
