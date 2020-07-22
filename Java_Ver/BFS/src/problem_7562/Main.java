/*
  #. [ 백준 7562_나이트의 이동 Silver II ]

  #. 문제
         체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 
         나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?
  
  #. 입력
         입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
         각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 
         체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 
         둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.
  
  #. 출력 
         각 테스트 케이스마다 나이트가 몇 번만에 이동할 수 있는지 출력한다.
         
  #. 예제 입력 1 
     3
     8
     0 0
     7 0
     100
     0 0
     30 50
     10
     1 1
     1 1
     
  #. 예제 출력 1 
     5
     28
     0
 */

/*
 *  #. 나의 풀이법.
 *     - BFS을 통하여, 나이트가 갈 수 있는 곳에 그 위치에 오기 위한 경로 수를 저장한다.
 *     - Queue를 사용하기 때문에, 현재 위치의 경로 수는 '현재 위치까지 몇번 만에 올 수 있는지 최단 거리'이다.
 * 
 */
package problem_7562;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


//좌표 저장 Class
class Pair {
	
	private int i;
	private int j;
	
	Pair(int i, int j) {
		this.i = i;
		this.j = j;
	}
	
	int getI() { return this.i; }
	int getJ() { return this.j; }
}

public class Main {
	
	private int testCase;
	private int n;
	private int[][] map;
	private boolean[][] check;
	
	//나이트의 이동 가능 경로. 총 8가지가 존재한다. 
	private int[] di = {-2, -2, -1, -1,  1, 1,  2, 2};
	private int[] dj = {-1,  1, -2,  2, -2, 2, -1, 1};
	
	//생성자를 통한 배열 멤버변수 중 배열 초기화
	public Main() {
		this.map = new int[300][300];
		this.check = new boolean[300][300];
	}
	
	//BFS수행 target좌표를 만나게 되면, break건다.
	public int bfs(int start_i, int start_j, int target_i, int target_j) {
		
		Queue<Pair> q = new LinkedList<>();
		
		q.add(new Pair(start_i, start_j));
		check[start_i][start_j] = true;
		
		while(!q.isEmpty()) {
			
			Pair p = q.remove();
			
			//Queue에서 꺼낸 값이 target좌표이면, 더 이상 수행하지 않는다.
			if(p.getI() == target_i && p.getJ() == target_j) {
				break;
			}
			
			//현재 위치로 부터, 나이트가 갈 수 있는 다음 위치 탐색.
			for(int k = 0; k < di.length; k++) {
				int next_i = p.getI() + di[k];
				int next_j = p.getJ() + dj[k];
				
				//범위 안에 존재하고,
				if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n) {
					//기록되지 않은 곳이며, 방문하지 않는 곳이면,
					if(map[next_i][next_j] == 0 && check[next_i][next_j] == false) {
						//현재위치 + 1하여 '몇번 만에 올 수 있는지' 기록한다.
						map[next_i][next_j] = map[p.getI()][p.getJ()] + 1;
						//방문처리하고
						check[next_i][next_j] = true;
						//Queue에 삽입한다.
						q.add(new Pair(next_i, next_j));
					}
				}
			}
		}
		
		return map[target_i][target_j];
	}
	
	public int[] solution() throws IOException {
		
		int[] answer;
		//
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line = br.readLine();
		this.testCase = Integer.parseInt(line);
		
		answer = new int[testCase];
		int i = 0;
		while(i < testCase) {
			
			String str_n = br.readLine();
			String str_start = br.readLine();
			String str_end = br.readLine();
			
			this.n = Integer.parseInt(str_n);
	
			StringTokenizer st = new StringTokenizer(str_start);		
			int start_i = Integer.parseInt(st.nextToken());
			int start_j = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(str_end);
			int target_i = Integer.parseInt(st.nextToken());
			int target_j = Integer.parseInt(st.nextToken());
			
			
			int result = bfs(start_i, start_j, target_i, target_j);
			answer[i] = result;
			
			map = new int[300][300];
			check = new boolean[300][300];
			
			i++;
		}
		return answer;
	}
	
	public void printResult(int[] answer) {
		for(int i : answer)
			System.out.println(i);
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		m.printResult(m.solution());
	}
}
