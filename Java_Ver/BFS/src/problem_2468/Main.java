

package problem_2468;

import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

class Pair {
	int x;
	int y;
	
	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {

	private int n;
	private int[][] map;
	private boolean[][] check;
	private int[] di = { -1, 0, 1, 0};
	private int[] dj = { 0, -1, 0, 1};
	
	public Main()
	{
		this.map = new int[100][100];
		this.check = new boolean[100][100];
	}
	
	public void bfs(int height, int i, int j) {
		Queue<Pair> q = new LinkedList<>();
		
		q.add(new Pair(i,j));
		check[i][j] = true;
		
		while(!(q.isEmpty())) {
			
			//
			Pair curr = q.remove();
			
			for(int k  = 0; k < 4; k++) {
				int next_i = curr.x + di[k];
				int next_j = curr.y + dj[k];
				
				if(next_i >= 0 && next_i < n && next_j >= 0 && next_j < n) {
					if(map[next_i][next_j] > height && check[next_i][next_j] == false) {
						check[next_i][next_j] = true;
						q.add(new Pair(next_i, next_j));
					}
				}
			}
			
		}
	}
	
	public int solution() {
		//
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		int answer = 1;
		int max = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
				if(max <  map[i][j])
					max = map[i][j];
			}
		}
		
		
		//
		for(int h = 1; h <= max; h++) {
			int height = h;
			int safety_zone = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(map[i][j] > height && check[i][j] == false) {
						bfs(height, i, j);
						safety_zone++;
					}
				}
			}
		
			check = new boolean[n][n];
			if(answer < safety_zone)
				answer = safety_zone;
		}
		
		return answer;
	}
	
	public static void main(String[] args) {
		
		Main sol = new Main();
		
		int answer = sol.solution();
		System.out.println(answer);
	}
}

















