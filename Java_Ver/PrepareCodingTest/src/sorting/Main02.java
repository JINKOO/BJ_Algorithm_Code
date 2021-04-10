package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// https://www.acmicpc.net/problem/11656
// 접미사 배열

public class Main02 {

	public void solution() throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		ArrayList<String> list = new ArrayList<>();
		for (int i = 0; i < input.length(); i++) {
			list.add(input.substring(i, input.length()));
		}
		
		Collections.sort(list);
		
		for (String str : list)
			System.out.println(str);
	}
	
	public static void main(String[] args) throws IOException {
		
		Main02 m = new Main02();
		
		m.solution();
	}
}
