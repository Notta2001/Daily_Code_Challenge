public class InterleavingString {
	public static boolean isInterleave(String s1, String s2, String s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if(len3 != (len1 + len2)) return false;
		boolean[][] dp = new boolean[len1+1][len2+1];
		
		// Fill in first column
		dp[0][0] = true;
		for(int i = 0; i < len1; ++i) {
			dp[i + 1][0] = (s3.charAt(i) == s1.charAt(i) && dp[i][0] == true) ? true : false;
		}
		
		// Fill in first row
		for(int i = 0; i < len2; ++i) {
			dp[0][i + 1] = (s3.charAt(i) == s2.charAt(i) && dp[0][i] == true) ? true : false;
		}
		for(int i = 1; i <= len1; ++i) {
			for(int j = 1; j <= len2; ++j) {
				if((s3.charAt(i + j - 1) == s1.charAt(i - 1) && dp[i - 1][j] == true) || (s3.charAt(i + j - 1) == s2.charAt(j - 1) && dp[i][j - 1] == true) ) {
					dp[i][j] = true;
				}
				else dp[i][j] = false;
				//System.out.println(dp[i][j]);
			}
		}
		
		return dp[len1][len2];
	}
	
	public static void main(String[] args) {
		System.out.println(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
	}
}
