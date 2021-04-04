package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

// https://www.acmicpc.net/problem/2583

class Point {
	
	public int i;
	public int j;
	
	Point(int i, int j) {
		this.i = i;
		this.j = j;
	}
}

public class BOJ_2583 {

	private int[][] board;
	private boolean[][] visited;
	private int[] di = {-1, 0, 1, 0};
	private int[] dj = {0, -1, 0, 1};
	private int M, N, K;
	
	public int bfs(int i, int j) {
		
		int count = 0;
		
		// 1. queue선언
		Queue<Point> queue = new LinkedList<>();
		
		queue.add(new Point(i, j));
		visited[i][j] = true;
		
		while (!queue.isEmpty()) {
			
			Point curr = queue.poll();
			count++;
			
			for (int d = 0; d < di.length; d++) {
				
				int ni = curr.i + di[d];
				int nj = curr.j + dj[d];
				
				if (0 <= ni && ni < M && 0 <= nj && nj < N) {
					if (board[ni][nj] == 0 && visited[ni][nj] == false) {
						queue.add(new Point(ni, nj));
						visited[ni][nj] = true;
					}
				}
			}
		}
		
		return count;
	}
	
	public void solution() throws IOException {
		
		// 1. M, N, K입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");

		M = Integer.valueOf(input[0]);
		N = Integer.valueOf(input[1]);
		K = Integer.valueOf(input[2]);
		
		board = new int[M][N];
		visited = new boolean[M][N];
		
		// 2. K만큼 반복하면서 좌표 입력 받고, 해당 좌표는 false check한다.
		while (K > 0) {
			
			String[] pos = br.readLine().split(" ");
			int x1 = Integer.valueOf(pos[0]);
			int y1 = Integer.valueOf(pos[1]);
			int x2 = Integer.valueOf(pos[2]) - 1;
			int y2 = Integer.valueOf(pos[3]) - 1;
			
			for (int y = y1; y <= y2; y++) {
				for (int x = x1; x <= x2; x++) {
					if (board[y][x] != -1)
						board[y][x] = -1;
				}
			}
			K--;
		}
		
		
		// 3. bfs() 수행한다.
		LinkedList<Integer> result = new LinkedList<>();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				// System.out.print(board[i][j] + " ");
				if (board[i][j] == 0 && visited[i][j] == false) {
					result.add(bfs(i, j));
				}
			}
		}
		
		System.out.println(result.size());
		
		if (result.size() > 0) {
			Collections.sort(result);
			for (int i : result)
				System.out.print(i + " ");
		}
	}

	public static void main(String[] args) throws IOException {

		BOJ_2583 sol = new BOJ_2583();
		
		sol.solution();
	}
}