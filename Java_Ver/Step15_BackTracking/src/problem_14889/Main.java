/*
 *   #. [ 백준_14889번 스타트와 링크 ] Silver III
 *   
 *   #. 문제
 *      오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 
 *      축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
 *      
 *      BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 
 *      능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.
 *      N=4이고, S가 아래와 같은 경우를 살펴보자.
 *      
 *      i\j	1	2	3	4
 *      1	 	1	2	3
 *      2	4	 	5	6
 *      3	7	1	 	2
 *      4	3	4	5	 
 *      
 *      예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.
 *      스타트 팀: S12 + S21 = 1 + 4 = 5
 *      링크 팀: S34 + S43 = 2 + 5 = 7
 *      
 *      1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.
 *      스타트 팀: S13 + S31 = 2 + 7 = 9
 *      링크 팀: S24 + S42 = 6 + 4 = 10
 *      축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 
 *      위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.
 *      
 *   #. 입력
 *      첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 
 *      둘째 줄부터 N개의 줄에 S가 주어진다. 각줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. 
 *      Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
 *      
 *   #. 출력
 *      첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.
 *      
 *   #. 예제 입력 1 
 *      4
 *      0 1 2 3
 *      4 0 5 6
 *      7 1 0 2
 *      3 4 5 0
 *   #. 예제 출력 1
 *      0
 *   
 *   #. 예제 입력 2 
 *      6
 *      0 1 2 3 4 5
 *      1 0 2 3 4 5
 *      1 2 0 3 4 5
 *      1 2 3 0 4 5
 *      1 2 3 4 0 5
 *      1 2 3 4 5 0
 *   #. 예제 출력 2 
 *      2
 *   
 *   #. 예제 입력 3 
 *      8
 *      0 5 4 5 4 5 4 5
 *      4 0 5 1 2 3 4 5
 *      9 8 0 1 2 3 1 2
 *      9 9 9 0 9 9 9 9
 *      1 1 1 1 0 1 1 1
 *      8 7 6 5 4 0 3 2
 *      9 1 9 1 9 1 0 9
 *      6 5 4 3 2 1 9 0
 *   #. 예제 출력 3 
 *      1
 *      
 *   #. 힌트
 *      예제 2의 경우에 (1, 3, 6), (2, 4, 5)로 팀을 나누면 되고, 
 *      예제 3의 경우에는 (1, 2, 4, 5), (3, 6, 7, 8)로 팀을 나누면 된다.
 */

/**
 *   #. 나의 풀이법.
 *      1. start팀으로 나누면, 나머지 인원은 link팀이 된다.
 *         백트래킹을 이용하고 check배열을 사용하여 팀을 나눈다.
 *         이때, 팀을 나누는 것에서 백트래킹이 사용된다.
 *      
 *      2. 각 나눈 팀에서 팀의 총 능력치를 계산한다. 
 *         total_start += (map[i][j] + map[j][i])
 *         total_link += (map[i][j] + map[j][i])
 *      
 *      3. 정답 = getMin(abs(total_start - total_link), min);    
 */

package problem_14889;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	private int n;
	private int[] numbers;
	private boolean[] check;
	private int[][] map;
	private int min = 100;
	
	//팀을 나누는 것이 백트래킹이며, 모든 경우를 따진다.
	public void dfs(int index, int count) {
		
		if(count == this.n/2) {
			LinkedList<Integer> startTeam = new LinkedList<>();
			LinkedList<Integer> linkTeam = new LinkedList<>();
			int total_start = 0, total_link = 0;
			//팀 나누기
			for(int i = 1; i <= n; i++) {
				if(check[i])
					startTeam.add(i);
				else
					linkTeam.add(i);
			}
			
			//각 팀의 능력치 구하기
			for(int i = 0; i < startTeam.size(); i++) {
				int iStart = startTeam.get(i);
				int iLink = linkTeam.get(i);
				for(int j = i + 1; j < startTeam.size(); j++) {
					int jStart = startTeam.get(j);
					int jLink = linkTeam.get(j);
			
					total_start += (map[iStart][jStart] + map[jStart][iStart]);
					total_link += (map[iLink][jLink] + map[jLink][iLink]);
				}
			}
			
			//각 경우에서 각 팀의 능력치 차이 구하고 최솟값 구하기
			if(Math.abs(total_start - total_link) < this.min)
				this.min = Math.abs(total_start - total_link);
			
			return;
		}
		
		for(int i = index; i <= n; i++) {
			if(!check[i]) {
				check[i] = true;
				dfs(i + 1, count + 1);
				check[i] = false;
			}
		}
	}
	
	public int solution() {
		int answer = 0;
		//
		dfs(1, 0);
		answer = this.min;
		//
		return answer;
	}

	public void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String inputN = br.readLine();
		this.n = Integer.parseInt(inputN);
		this.numbers = new int[this.n + 1];
		this.check = new boolean[this.n + 1];
		this.map = new int[this.n+1][this.n+1];
		
		for (int i = 1; i <= this.n; i++) {
			this.numbers[i] = i;
			String inputMap = br.readLine();
			StringTokenizer stk = new StringTokenizer(inputMap, " ");
			int j = 1;
			while (stk.hasMoreTokens()) {
				this.map[i][j++] = Integer.parseInt(stk.nextToken());
			}
		}
	}

	public static void main(String[] args) throws IOException {

		Main m = new Main();
		
		m.init();
		System.out.println(m.solution());
	}
}
