/*
  #. [ 백준 10026_적록색약 Gold V ]
  
  #. 문제
         적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
         크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 
         구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
    (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
    
        예를 들어, 그림이 아래와 같은 경우에
        
        RRRBB
        GGBBB
        BBBRR
        BBRRR
        RRRRR
        
        적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 
        하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
        
        그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

  #. 입력
     - 첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
     - 둘째 줄부터 N개 줄에는 그림이 주어진다.

  #. 출력
          적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

  #. 예제 입력 1 
     5
     RRRBB
     GGBBB
     BBBRR
     BBRRR
     RRRRR
     
  #.예제 출력 1 
    4 3
 */

/*
 *   #. 나의 풀이법.
 *      - 본 문제는 dfs, bfs모두 가능하다.
 *      - 정상인 사람들의 각 RGB영역 계산은 기존의 BFS방식을 적용하면 된다.
 *      - 적록색약인 사람들을 구할 때, != 'B'를 사용하여, 또 다른 BFS를 수행하려 했다.
 *      - 테이스케이스 모두 통과했지만, 뭔가 찜찜한 느낌... 기존의 BFS를 그대로 사용하고 싶다.
 *      - 아, 처음 map을 입력 받을 때, String map[i]로 선언하였다...
 *      
 *   #. 좀 더 효율적인 방법.
 *      - 'R', 'G'를 같은 색으로 보는 것이 핵심이다.
 *      - 적룍색약이 아닌 사람들을 탐색하고 나서, map의 구성을 변경한다.
 *        if(map[i][j] == 'R')
 *           map[i][j] = 'G'
 *        이렇게 하면, G인 것만 탐색하면 된다.
 *      - 기존의 BFS함수를 그대로 사용 할 수 있다. 
 */

package problem_10026;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Point {
	
	int i;
	int j;
	
	Point(int i, int j) {
		this.i = i;
		this.j = j;
	}
}

public class Main {
	
	private int n;
	private char[][] map;
	private boolean[][] check;
	
	private int[] di = {-1,0,1,0};
	private int[] dj = {0,-1,0,1};
	
	
	public Main() {
		this.n = 0;
		this.map = new char[100][100];
		this.check = new boolean[100][100];
	}
	
	public void bfs(char targetRGB, int i, int j) {
		
		Queue<Point> q = new LinkedList<>();
		
		q.offer(new Point(i, j));
		check[i][j] = true;
		
		while(!q.isEmpty()) {
			
			Point curr = q.poll();
			
			for(int k = 0; k < 4; k++) {
				int ni = curr.i + di[k];
				int nj = curr.j + dj[k];
				
				if(0 <= ni && ni < n && 0 <= nj && nj < n) {
					if(map[ni][nj] == targetRGB && check[ni][nj] == false) {
						check[ni][nj] = true;
						q.offer(new Point(ni, nj));
					}
				}
			}
		}
	}
	
	public int[] solution() throws IOException {
		
		int[] answer = new int[2];
		
		//
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//1. n입력 받기.
		this.n = Integer.parseInt(br.readLine());
		
		//2. RGB map초기화
		for(int i = 0; i < n; i++) {
			String line = br.readLine();
			for(int j = 0; j < n; j++) {
				map[i][j] = line.charAt(j);
			}
		}
		
		
		int normal = 0;
		int notNormal = 0;
		int count = 0;
		//3.BFS탐색.
		char[] rgb = {'R','G','B'};
		int[] temp = new int[3];         //각 RGB영역 개수 저장 배열.
		//3.1 정상인
		for(int r = 0; r < rgb.length; r++) {
			char target_RGB = rgb[r];
			count = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(map[i][j] == target_RGB && check[i][j] == false) {
						bfs(target_RGB, i, j);
						count++;
					}
				}
			}
			check = new boolean[100][100];
			temp[r] = count;
			normal += count;
		}
		
		//4. R을 G로 변경한다.
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == 'R')
					map[i][j] = 'G';
			}
		}
		
		//5. 적록색약 탐색 시작.
		count = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <n; j++) {
				if(map[i][j] == 'G' && check[i][j] == false) {
					bfs('G', i,j);
					count++;
				}
			}
		}
		
		notNormal = count + temp[2];
		
		answer[0] = normal;
		answer[1] = notNormal;
		
		//
		return answer;
	}
	
	public void printResult(int[] answer) {
		for(int i : answer)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		m.printResult(m.solution());
	}
}






















