public class InterleavingStringII {
	public static boolean isInterleave(String s1, String s2, String s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if(len3 != (len1 + len2)) return false;
		boolean[] dp = new boolean[len2 + 1];
		dp[0] = true;
		// fill in first row 
		for(int i = 0; i < len2; ++i) {
			dp[i + 1] = (s2.charAt(i) == s3.charAt(i) && dp[i] == true) ? true : false;
		}
		
		for(int i = 1; i <= len1; ++i) {
			for(int j = 0; j <= len2; ++j) {
				if(j == 0) {
					dp[0] = (dp[0] == true && s1.charAt(i-1) == s3.charAt(i-1)) ? true : false;
				}
				else {
					if((s3.charAt(i + j - 1) == s1.charAt(i - 1) && dp[j] == true) || (s3.charAt(i + j - 1) == s2.charAt(j - 1) && dp[j-1] == true)) {
						dp[j] = true;
					}
					else dp[j] = false;
				}
			}
		}
		
		return dp[len2];
	}
	
	public static void main(String[] args) {
		System.out.println(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
	}
}
