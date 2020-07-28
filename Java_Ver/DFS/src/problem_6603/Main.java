/*
 *  #. [백준_6603번 로또 ] Silver II
 *  
 *  #. 문제
 *     독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
 *     로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
 *     예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. 
 *     ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
 *     
 *     집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
 *     
 *  #. 입력
 *     입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 
 *     첫 번째 수는 k (6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.
 *     입력의 마지막 줄에는 0이 하나 주어진다. 
 *     
 *  #. 출력
 *     각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 이때, 사전 순으로 출력한다.
 *     각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.
 *     
 *  #. 예제 입력 1 
 *     7 1 2 3 4 5 6 7
 *     8 1 2 3 5 8 13 21 34
 *     0
 *     
 *  #. 예제 출력 1
 *     1 2 3 4 5 6
 *     1 2 3 4 5 7
 *     1 2 3 4 6 7
 *     1 2 3 5 6 7
 *     1 2 4 5 6 7
 *     1 3 4 5 6 7
 *     2 3 4 5 6 7
 *     
 *  #. 예제 출력 2 (길어서 생략. 백준 사이트 직접 보기)
 *  
 *  
 *  ###. 비슷한 문제 :: 프로그래머스 Level 3 '여행 경로'
 *                  프로그래머스 Level 2 '타겟 넘버'
 *                        백준  14502번    '연구소'  
 * 
 */

/*
 *  #. 나의 풀이법.
 *     - 해결 하지 못하였다. 백트래킹 기법을 사용하는 것이라는데..
 *     - 우선 구글링해서 코드는 작성함.
 * 
 */
package problem_6603;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private int n;
	private boolean[] check;

	public void dfs(int[] lotto, int index, int count) {

		if (index <= lotto.length && count == 3) {
			String str = "";
			for (int i = 0; i < lotto.length; i++) {
				if (check[i] == true)
					str += lotto[i] + " ";
			}

			System.out.println(str);
			return;
		}

		for (int k = index; k < lotto.length; k++) {
			check[k] = true;
			dfs(lotto, k + 1, count + 1);
			check[k] = false;
		}
	}

	public void solution() throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {

			String line = br.readLine();
			StringTokenizer stk = new StringTokenizer(line, " ");

			this.n = Integer.valueOf(stk.nextToken());
			if (this.n == 0)
				break;

			int[] lotto = new int[this.n];
			int i = 0;
			while (stk.hasMoreTokens()) {
				lotto[i++] = Integer.valueOf(stk.nextToken());
			}

			this.check = new boolean[lotto.length];
			dfs(lotto, 0, 0);

		}
	}

	public static void main(String[] args) throws IOException {

		Main m = new Main();
		m.solution();
	}
}
