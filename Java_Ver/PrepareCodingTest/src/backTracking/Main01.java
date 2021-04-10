package backTracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

// https://www.acmicpc.net/problem/15649
// N과 M(1)

public class Main01 {
	
	private int n;
	private int m;
	private ArrayList<Integer> list = new ArrayList<>();
	private ArrayList<Integer> temp = new ArrayList<>();
	private boolean[] visited;
	
	public void backTracking(int index) {
		
		if (temp.size() == this.m) {
			for (Integer i : temp)
				System.out.print(i + " ");
			System.out.println();
			return;
		}
		
		for (int i = 0; i < list.size(); i++) {
			
			if (visited[i] == false) {
				visited[i] = true;
				temp.add(list.get(i));
				backTracking(index + 1);
				temp.remove(temp.size() - 1);
				visited[i] = false;
			}
		}
	}
	
	public void solution() throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		
		this.n = Integer.parseInt(input[0]);
		this.m = Integer.parseInt(input[1]);
		
		visited = new boolean[this.n];
		for (int i = 0; i < n; i++) {
			list.add(i + 1);
		}
		
		this.backTracking(0);
		
	}
	
	public static void main(String[] args) throws IOException {
		
		Main01 m = new Main01();
		
		m.solution();
	}
}
