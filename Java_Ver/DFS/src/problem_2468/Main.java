/*
 * #.[ 백준 2468_안전 영역 Silver I ]
  
   #.문제
          재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 먼저 어떤 지역의 높이 정보를 파악한다. 
	  그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다. 
	  이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.
	 
	  어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다. 
	  예를 들어, 다음은 N=5인 지역의 높이 정보이다.
	 
	 
	  이제 위와 같은 지역에 많은 비가 내려서 높이가 4 이하인 모든 지점이 물에 잠겼다고 하자. 
	  이 경우에 물에 잠기는 지점을 회색으로 표시하면 다음과 같다. 
	  물에 잠기지 않는 안전한 영역이라 함은 물에 잠기지 않는 지점들이 위, 아래, 오른쪽 혹은 왼쪽으로 인접해 있으며 그 크기가 최대인 영역을 말한다. 
	  위의 경우에서 물에 잠기지 않는 안전한 영역은 5개가 된다(꼭짓점으로만 붙어 있는 두 지점은 인접하지 않는다고 취급한다). 
	 
	  또한 위와 같은 지역에서 높이가 6이하인 지점을 모두 잠기게 만드는 많은 비가 내리면 물에 잠기지 않는 안전한 영역은 
	  아래 그림에서와 같이 네 개가 됨을 확인할 수 있다. 
	 
	  이와 같이 장마철에 내리는 비의 양에 따라서 물에 잠기지 않는 안전한 영역의 개수는 다르게 된다. 
	  위의 예와 같은 지역에서 내리는 비의 양에 따른 모든 경우를 다 조사해 보면 물에 잠기지 않는 안전한 영역의 개수 중에서 최대인 경우는 5임을 알 수 있다. 
	 
	  어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오. 

  #. 입력
     - 첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. 
	 - N은 2 이상 100 이하의 정수이다. 
	 - 둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다. 
	 - 각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다. 높이는 1이상 100 이하의 정수이다.

  #. 출력
         첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.

  #. 예제 입력 1 
     5
	 6 8 2 6 2
	 3 2 3 4 6
	 6 7 3 3 2
	 7 2 5 3 6
	 8 9 5 2 7
  #. 예제 출력 1 
     5

  #. 노트
     아무 지역도 물에 잠기지 않을 수도 있다.
 */
package problem_2468;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {

	private int n;
	private int[][] map;
	private boolean[][] check;
	private int[] di = {-1, 0, 1, 0};
	private int[] dj = {0, -1, 0, 1};
	
	public Main() {
		this.map = new int[100][100];
		this.check = new boolean[100][100];
	}
	
	public int init() throws IOException {
		//1. Scanner class대신에 다음과 같이 입력 받으면 속도가 더 빠르다.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//2. n입력 받기. 정수이므로 String으로 입력 받은 것을 파싱해야 한다.
		String line = br.readLine();
		this.n = Integer.parseInt(line);
		
		
		//3. map의 각 원소 높이 초기화. 이때, map의 원소에서 가장 큰 값을 찾는다.
		//   BFS수행 할 때, max이후는 어차피 모두 물에 잠기므로 안전영영의 크기는 항상 1이다.
		int max = 0;
		for(int i = 0; i < n; i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str, " ");
			for(int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(max < map[i][j])
					max = map[i][j];
			}
		}
		return max;
	}
	
	public void dfs(int height, int i, int j) {
		
		if(check[i][j] == true)
			return;
		
		check[i][j] = true;
		
		for(int k = 0; k < 4; k++) {
			int next_i = i + di[k];
			int next_j = j + dj[k];
			
			if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n) {
				if(map[next_i][next_j] > height && check[next_i][next_j] == false)
					dfs(height, next_i, next_j);
			}
		}
	}
	
	public int solution() throws IOException {
		
		int answer = 1;
		//
		int maxHeight = init();
		
		for(int h = 1; h <= maxHeight; h++) {
			int safety_zone = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(map[i][j] > h && check[i][j] == false) {
						dfs(h, i, j);
						safety_zone++;
					}
				}
			}
			//h에 대한 탐색이 끝날 때 마다, check배열 초기화.
			check = new boolean[n][n];
			if(answer < safety_zone)
				answer = safety_zone;
		}
		//
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		int answer = m.solution();
		System.out.println(answer);
	}
}
