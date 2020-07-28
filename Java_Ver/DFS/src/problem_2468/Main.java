
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
		//1. 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//2. 
		String line = br.readLine();
		this.n = Integer.parseInt(line);
		
		
		//3.
		//   
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
			//h
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
