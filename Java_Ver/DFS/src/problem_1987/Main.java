/*
 *  #. [ 백준_1987번 알파벳 ] Gold IV
 *  
 *  #. 문제
 *     세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 
 *     좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
 *     
 *     말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
 *     즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
 *     좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
 *     
 *  #. 입력
 *     - 첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 
 *     - 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.
 *      
 *  #. 출력
 *     첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.
 *      
 *  #. 예제 입력 1 
 *     2 4
 *     CAAB
 *     ADCB
 *   
 *  #. 예제 출력 1 
 *     3
 */

package problem_1987;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private int r;
	private int c;
	private char[][] board;
	private int[][] record;
	private boolean[] alphabet;
	private int[] di = { -1, 0, 1, 0 };
	private int[] dj = { 0, -1, 0, 1 };

	public Main() {
		this.alphabet = new boolean[26];
	}

	public void dfs(int i, int j) {

		System.out.println(i + " " + j);
		if (alphabet[board[i][j] - 65] == true)
			return;

		alphabet[board[i][j] - 65] = true;
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if (0 <= ni && ni < r && 0 <= nj && nj < c) {
				if (alphabet[board[ni][nj] - 65] == false && record[ni][nj] == 0) {
					this.record[ni][nj] = record[i][j] + 1;
					dfs(ni, nj);
				}
			}
		}
	}

	public int solution() throws IOException {

		int answer = 0;
		//
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputSize = br.readLine();

		StringTokenizer stk = new StringTokenizer(inputSize, " ");
		this.r = Integer.valueOf(stk.nextToken());
		this.c = Integer.valueOf(stk.nextToken());

		this.board = new char[r][c];
		this.record = new int[r][c];

		for (int i = 0; i < r; i++) {
			String alphabet = br.readLine();
			for (int j = 0; j < c; j++) {
				this.board[i][j] = alphabet.charAt(j);
			}
		}

		this.record[0][0] = 1;
		dfs(0, 0);

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (answer < record[i][j])
					answer = record[i][j];
			}
		}

		//
		return answer;

	}

	public static void main(String[] args) throws IOException {

		Main m = new Main();

		System.out.println(m.solution());

	}
}
