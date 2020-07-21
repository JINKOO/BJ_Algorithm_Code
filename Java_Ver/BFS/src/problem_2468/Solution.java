package problem_2468;
/*
 * #. [ ���� 2468_���� ���� Silver I ]
  
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

public class Solution {

	private int n;
	private int[][] map;
	private boolean[][] check;
	private int[] di = { -1, 0, 1, 0};
	private int[] dj = { 0, -1, 0, 1};
	
	public Solution()
	{
		this.map = new int[100][100];
		this.check = new boolean[100][100];
	}
	
	public void bfs(int height, int i, int j) {
		Queue<Pair> q = new LinkedList<>();
		
		q.add(new Pair(i,j));
		check[i][j] = true;
		
		while(!(q.isEmpty())) {
			
			//java������ remove�ϸ�, queue�� �պκ� ���Ұ� ���ϵǰ�, ���� �ȴ�.
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
		//n�Է� �ޱ�
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
		
		
		//max������ h�� ���� ��� ����� ���� ������ �ȴ�. max���ķ� ��� ���� ���� �ȴ�.
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
		
		Solution sol = new Solution();
		
		int answer = sol.solution();
		System.out.println(answer);
	}
}

















