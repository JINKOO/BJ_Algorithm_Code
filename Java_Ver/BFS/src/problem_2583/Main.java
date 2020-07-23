/*
  #. [ 백준 2583_영역 구하기 Silver I ]
  
  #. 문제
         눈금의 간격이 1인 M × N(M,N ≤ 100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
         이 들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
         
         예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
     
         0 1 0 0 0 0 0
         1 1 1 1 0 0 0
         1 1 1 1 0 0 0
         0 1 0 0 1 1 0
         0 0 0 0 1 1 0
         
     <그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
     
     M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.
  
  #. 입력
     - 첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
     - 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 
     - 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 
     - 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

  #. 출력
     - 첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 
     - 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

  #. 예제 입력 1 
     5 7 3
     0 2 4 4
     1 1 2 5
     4 0 6 2
  #. 예제 출력 1 
     3
     1 7 13
*/


package problem_2583;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


class Point {
	
	int x;
	int y;
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}


public class Main {

	private int n;
	private int m;
	private int k;
	private int[][] map;
	private boolean[][] check;
	private int[] dx = {-1,0,1,0};
	private int[] dy = {0,-1,0,1};
	private int area;
	private ArrayList<Integer> answer;
	
	public Main() {
		this.map = new int[100][100];
		this.check = new boolean[100][100];
		this.area = 0;
		this.answer = new ArrayList<Integer>();
	}
	
	public void makeWall(Point p1, Point p2) {
		
		for(int y = p1.y; y < p2.y; y++) {
			for(int x = p1.x; x < p2.x; x++) {
				if(map[y][x] == 0)
					map[y][x] = 1;
			}
		}
	}
	
	public int bfs(int x, int y) {
		
		int zero_count = 0;
		Queue<Point> q = new LinkedList<>();
		
		q.offer(new Point(x, y));
		check[y][x] = true;
		
		while(!q.isEmpty()) {
			
			Point curr = q.poll();
			
			for(int k = 0; k < 4; k++) {
				int nx = curr.x + dx[k];
				int ny = curr.y + dy[k];
				
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					if(map[ny][nx] == 0 && check[ny][nx] == false) {
						check[ny][nx] = true;
						q.offer(new Point(nx, ny));
					}
				}
			}
			zero_count++;
		}
		return zero_count;
	}
	
	public void solution() throws IOException {
		
		//
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//1. n, m, k 입력 받기.
		String line = br.readLine();
		StringTokenizer stk = new StringTokenizer(line, " ");
		
		this.m = Integer.parseInt(stk.nextToken());
		this.n = Integer.parseInt(stk.nextToken());
		this.k = Integer.parseInt(stk.nextToken());
		
		//3. k만큼 직사각형 좌표 입력 받고, 직사각형 범위안에 있는 좌표들은 '1'표시하기(벽세우기) 
		for(int p = 0; p < k; p++) {
			String points = br.readLine();
			stk = new StringTokenizer(points, " ");
			
			int x1 = Integer.parseInt(stk.nextToken());
			int y1 = Integer.parseInt(stk.nextToken());
			int x2 = Integer.parseInt(stk.nextToken());
			int y2 = Integer.parseInt(stk.nextToken());
			
			Point p1 = new Point(x1, y1);
			Point p2 = new Point(x2, y2);
			
			makeWall(p1, p2);
		}
		
		
//		for(int y = 0; y < m; y++) {
//			for(int x = 0; x < n; x++) {
//				System.out.print(map[y][x] + " ");
//			}
//			System.out.println();
//		}
		
		
		//4. 완성된 map을 가지고, BFS수행 한다.
		for(int y = 0; y < m; y++) {
			for(int x = 0; x < n; x++) {
				if(map[y][x] == 0 && check[y][x] == false) {
					int zero_count = bfs(x, y);
					area++;
					answer.add(zero_count);
				}
			}
		}
	}
	
	//5. 결과 출력
	public void printResult() {
		
		//5.1 분리된 영역의 개수
 		System.out.println(this.area);
		
 		//5.2 각 영역의 영역의 개수(오름 차순 정렬)
 		Collections.sort(answer, new Comparator<Integer>() {
 			@Override
 			public int compare(Integer i1, Integer i2) {
 				return i1.compareTo(i2);
 			}
 		});
 		
		for(int i : this.answer)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		m.solution();
		m.printResult();
	}
}