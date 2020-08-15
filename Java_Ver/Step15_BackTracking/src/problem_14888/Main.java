/*
 *   #. [ 백준_14888번 연산자 끼워넣기 ]
 *   
 *   #. 문제
 *      N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 
 *      또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
 *      연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
 *      우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.
 *      
 *      예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 
 *      곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 
 *      예를 들어, 아래와 같은 식을 만들 수 있다.
 *      1+2+3-4×5÷6
 *      1÷2+3+4-5×6
 *      1+2÷3×4-5+6
 *      1÷2×3-4+5+6
 *      
 *      식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 
 *      또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 
 *      즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 
 *      이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.
 *      
 *      1+2+3-4×5÷6 = 1
 *      1÷2+3+4-5×6 = 12
 *      1+2÷3×4-5+6 = 5
 *      1÷2×3-4+5+6 = 7
 *      
 *      N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
 *      
 *   #. 입력
 *      첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 
 *      둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
 *      셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 
 *     
 *   #. 출력
 *      첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 
 *      연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 
 *      또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.
 *      
 *   #. 예제 입력 1 
 *      2
 *      5 6
 *      0 0 1 0
 *   #. 예제 출력 1 
 *      30
 *      30
 *  
 *   #. 예제 입력 2 
 *      3
 *      3 4 5
 *      1 0 1 0
 *   #. 예제 출력 2 
 *      35
 *      17
 *   
 *   #. 예제 입력 3 
 *      6
 *      1 2 3 4 5 6
 *      2 1 1 1
 *   #. 예제 출력 3 
 *      54
 *      -24
 */

/**
 *   #. 나의 풀이법.
 *      - C++에서는 풀었다가 Java로 풀었을 때 왜 틀렸는지 모르겠다가 원인 파악함.
 *      - backTracking에서 연산자의 모든 경우의 수를 나열하는데
 *      - ArrayList<> combination에서 dfs후 맨 마지막 원소를 삭제해야 하는데  allOperators[i]의 index를 삭제함..
 *      - 결국 오류 고치고 해결함.
 *      
 *      - 문제 풀면서 가장 중요한 포인트.
 *        연산자의 개수 만큼 나열할 수 있는 모든 경우의 수 따진다.
 *        이때 각 경우에서 numbers의 숫자를 순서대로 연산하여 결과값을 만들고
 *        결과값을 min, max값과 비교하여 정답 만든다. 
 */

package problem_14888;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	private int n; 
	private int[] numbers = new int[20];
	private int[] operators = new int[4];
	private boolean[] check = new boolean[19];
	private ArrayList<Integer> allOperators = new ArrayList<>();
	private ArrayList<Integer> combination = new ArrayList<>();
	private long max = Long.MIN_VALUE;
	private long min = Long.MAX_VALUE;
	
	public void dfs(int count) {
		if(count == this.n-1)
		{
			long total = numbers[0];
			for(int i = 0; i < combination.size(); i++) {
				switch(combination.get(i)) {
				case 0: // +
					total += numbers[i + 1];
					break;
				case 1: // -
					total -= numbers[i + 1];
					break;
				case 2: // *
					total *= numbers[i + 1];
					break;
				case 3: // /
					total /= numbers[i + 1];
					break;
				}
			}
			if(max < total)
				max = total;
			
			if(min > total)
				min = total;
			
			return;
		}
		
		for(int i = 0; i < allOperators.size(); i++) {
			if(!check[i]) {
				check[i] = true;
				combination.add(allOperators.get(i));
				dfs(count + 1);
				combination.remove(combination.size() - 1);
				check[i] = false;
			}
		}
	}
	
	public long[] solution() {
		long[] answer = new long[2];
		//
		//1. 연산자 4개 입력 받은 것을 총 개수 만큼 펼치기
		//   2 1 1 1 --> +, +, -, *, / --> index를 삽입한다.
		for(int k = 0; k < 4; k++) {
			if(operators[k] > 1) {
				for(int p = 0; p < operators[k]; p++) 
					allOperators.add(k);
			}
			
			else if(operators[k] == 1)
				allOperators.add(k);
		}
		
		//2. dfs수행. 연산자 n-1개가 이룰 수 있는 모든 경우의 수
		dfs(0);
		
		answer[0] = max;
		answer[1] = min;
		//
		return answer;
	}
	
	public void printResult(long[] answer) {
		for(long i : answer)
			System.out.println(i);
	}
	
	public static void main(String[] args) throws IOException {
		
		Main m = new Main();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		m.n = Integer.parseInt(br.readLine());
		
		//m.numbers = new int[m.n];
		
		String inputNumbers = br.readLine();
		StringTokenizer stk = new StringTokenizer(inputNumbers, " ");
		int i = 0;
		while(stk.hasMoreTokens())
			m.numbers[i++] = Integer.parseInt(stk.nextToken());
		
		String inputOperatorCount = br.readLine();
		stk = new StringTokenizer(inputOperatorCount, " ");
		int j = 0;
		while(stk.hasMoreTokens())
			m.operators[j++] = Integer.parseInt(stk.nextToken());
		
		m.printResult(m.solution());
		
	}
}
