package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

// https://www.acmicpc.net/problem/7795
// 먹을 것인가 먹힐 것인가

public class Main03 {
	
	public void solution() throws IOException {
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.valueOf(br.readLine());
		int aSize = 0, bSize = 0;
		Integer[] aArr;
		Integer[] bArr;
		int count;
		
		while (T > 0) {
			
			count = 0;
			
			String[] sizeInput = br.readLine().split(" ");
			aSize = Integer.valueOf(sizeInput[0]);
			bSize = Integer.valueOf(sizeInput[1]);
			
			// System.out.println(aSize + " " + bSize);
			aArr = new Integer[aSize];
			bArr = new Integer[bSize];
			
			String[] aInput = br.readLine().split(" ");
			for (int i = 0; i < aArr.length; i++) {
				aArr[i] = Integer.valueOf(aInput[i]);
			}
			
			String[] bInput = br.readLine().split(" ");
			for (int i = 0; i < bArr.length; i++) {
				bArr[i] = Integer.valueOf(bInput[i]);
			}
			
			// sort desc
			Arrays.sort(aArr, Collections.reverseOrder());
			Arrays.sort(bArr, Collections.reverseOrder());
			
			
			for (int i = 0; i < aArr.length; i++) {
				for (int j = 0; j < bArr.length; j++) {
					if(aArr[i] > bArr[j]) {
						count++;
					}
				}
			}
			System.out.println(count);
			
			T--;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		Main03 m = new Main03();
		
		m.solution();
	}
}
