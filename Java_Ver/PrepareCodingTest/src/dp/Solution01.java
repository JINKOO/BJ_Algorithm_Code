package dp;

import java.util.*;

class Solution01 {
    
    private final int MOD = 1000000007;
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        // 1. dp 선언 후 1로 채우기
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], 1);
        }
        
        // 2. 물웅덩이
        for (int i = 0; i < puddles.length; i++) {
            
            int x = puddles[i][0] - 1;
            int y = puddles[i][1] - 1;
            
            System.out.println(x + ", " + y);
            
            // 일단 물웅덩이면, 해당 좌표 값은 0.
            dp[y][x] = 0;
            
            // ~ m에서 한 위치가 물웅덩이이면, 그 위치에서 부터 ~m까지는 모두 0 
            
            if (x == 0) {
                for (int k = y + 1; k < m; k++)
                    dp[0][k] = 0;
            }
            
            if (y == 0) {
                for (int k = x + 1; k < n; k++)
                    dp[k][0] = 0;
            }
            
        }
        
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		System.out.print(dp[i][j] + " ");
        	}
        	System.out.println();
        }
        
        System.out.println();
        
        // 점화식 계산
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i][j] == 0)
                    continue;
                
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		System.out.print(dp[i][j] + " ");
        	}
        	System.out.println();
        }
        
      
        answer = dp[n - 1][m - 1] % MOD;
        
        
        return answer;
    }
    
    public static void main(String[] args) {
		
    	Solution01 sol = new Solution01();
    	
    	int[][] puddles = {{2,2}};
    	
    	System.out.println(sol.solution(4, 3, puddles));
	}
}















