/*
 * #.[ ���� 2468_���� ���� Silver I ]
  
   #.����
          �糭����û������ ���� �� ������ �帶ö�� ����ؼ� ������ ���� ���� ��ȹ�ϰ� �ִ�. ���� � ������ ���� ������ �ľ��Ѵ�. 
	  �� ������ �� ������ ���� �� ������ �� ���� ����� �ʴ� ������ ������ �ִ�� �� ���� ����� ���� ���� �����Ϸ��� �Ѵ�. 
	  �̶�, ������ �����ϰ� �ϱ� ���Ͽ�, �帶ö�� ������ ���� �翡 ���� ������ ���� ������ ��� ������ ���� ���ٰ� �����Ѵ�.
	 
	  � ������ ���� ������ ��� ���� ũ�Ⱑ ���� N�� 2���� �迭 ���·� �־����� �迭�� �� ���Ҵ� �ش� ������ ���̸� ǥ���ϴ� �ڿ����̴�. 
	  ���� ���, ������ N=5�� ������ ���� �����̴�.
	 
	 
	  ���� ���� ���� ������ ���� �� ������ ���̰� 4 ������ ��� ������ ���� ���ٰ� ����. 
	  �� ��쿡 ���� ���� ������ ȸ������ ǥ���ϸ� ������ ����. 
	  ���� ����� �ʴ� ������ �����̶� ���� ���� ����� �ʴ� �������� ��, �Ʒ�, ������ Ȥ�� �������� ������ ������ �� ũ�Ⱑ �ִ��� ������ ���Ѵ�. 
	  ���� ��쿡�� ���� ����� �ʴ� ������ ������ 5���� �ȴ�(���������θ� �پ� �ִ� �� ������ �������� �ʴ´ٰ� ����Ѵ�). 
	 
	  ���� ���� ���� �������� ���̰� 6������ ������ ��� ���� ����� ���� �� ������ ���� ����� �ʴ� ������ ������ 
	  �Ʒ� �׸������� ���� �� ���� ���� Ȯ���� �� �ִ�. 
	 
	  �̿� ���� �帶ö�� ������ ���� �翡 ���� ���� ����� �ʴ� ������ ������ ������ �ٸ��� �ȴ�. 
	  ���� ���� ���� �������� ������ ���� �翡 ���� ��� ��츦 �� ������ ���� ���� ����� �ʴ� ������ ������ ���� �߿��� �ִ��� ���� 5���� �� �� �ִ�. 
	 
	  � ������ ���� ������ �־����� ��, �帶ö�� ���� ����� �ʴ� ������ ������ �ִ� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 

  #. �Է�
     - ù° �ٿ��� � ������ ��Ÿ���� 2���� �迭�� ��� ���� ������ ��Ÿ���� �� N�� �Էµȴ�. 
	 - N�� 2 �̻� 100 ������ �����̴�. 
	 - ��° �ٺ��� N���� �� �ٿ��� 2���� �迭�� ù ��° ����� N��° ����� ������� �� �྿ ���� ������ �Էµȴ�. 
	 - �� �ٿ��� �� ���� ù ��° ������ N��° ������ N���� ���� ������ ��Ÿ���� �ڿ����� �� ĭ�� ���̿� �ΰ� �Էµȴ�. ���̴� 1�̻� 100 ������ �����̴�.

  #. ���
         ù° �ٿ� �帶ö�� ���� ����� �ʴ� ������ ������ �ִ� ������ ����Ѵ�.

  #. ���� �Է� 1 
     5
	 6 8 2 6 2
	 3 2 3 4 6
	 6 7 3 3 2
	 7 2 5 3 6
	 8 9 5 2 7
  #. ���� ��� 1 
     5

  #. ��Ʈ
     �ƹ� ������ ���� ����� ���� ���� �ִ�.
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
		//1. Scanner class��ſ� ������ ���� �Է� ������ �ӵ��� �� ������.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//2. n�Է� �ޱ�. �����̹Ƿ� String���� �Է� ���� ���� �Ľ��ؾ� �Ѵ�.
		String line = br.readLine();
		this.n = Integer.parseInt(line);
		
		
		//3. map�� �� ���� ���� �ʱ�ȭ. �̶�, map�� ���ҿ��� ���� ū ���� ã�´�.
		//   BFS���� �� ��, max���Ĵ� ������ ��� ���� ���Ƿ� ���������� ũ��� �׻� 1�̴�.
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
			//h�� ���� Ž���� ���� �� ����, check�迭 �ʱ�ȭ.
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
