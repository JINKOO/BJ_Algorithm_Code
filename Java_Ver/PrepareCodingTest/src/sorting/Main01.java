package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// https://www.acmicpc.net/problem/5648
// 역 원소정렬
// 2021.04.10 50%에서 Runtime error가 발생한다.

public class Main01 {

	private ArrayList<StringBuffer> origin = new ArrayList<>();
	private ArrayList<Long> result = new ArrayList<>();
	private int N;

	public void init() throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] firstInputLine = br.readLine().split(" ");
		
		this.N = Integer.parseInt(firstInputLine[0]);
		for (int i = 1; i < firstInputLine.length; i++) {
			origin.add(new StringBuffer(firstInputLine[i]));
		}
		
		boolean isFull = false;
		while (origin.size() < this.N) {
			String[] input = br.readLine().split(" ");
			for (int i = 0; i < input.length; i++) {
				if (origin.size() == this.N) {
					isFull = true;
					break;
				}
				origin.add(new StringBuffer(input[i]));
			}
			if (isFull == true)
				break;
		}
	}

	public void solution() throws IOException {

		// 초기화
		this.init();
		
		// 문자열 뒤집기
		for (StringBuffer sb : origin) {
			// Test print
			// System.out.println(sb);
			
			// reverse
			// Test print
			// System.out.println(Integer.valueOf(sb.reverse().toString()));
			result.add(Long.parseLong(sb.reverse().toString()));
		}
		
		Collections.sort(result);
		
		for (Long l : result)
			System.out.println(l);
	}

	public static void main(String[] args) throws IOException {

		Main01 sol = new Main01();
		sol.solution();
	}
}
