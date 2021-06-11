public class StoneGameVII {
	public static int[][] dp = new int [1001][1001];
	public static int helper(int[] v , int i , int j , int sum){
	    if(i >= j || sum <= 0){
	        return 0;
	    }
	    if(dp[i][j] != -1){
	        return dp[i][j];
	    }
	    int x = sum-v[i] - helper(v,i+1,j,sum-v[i]);
	    int y = sum-v[j] - helper(v,i,j-1,sum-v[j]);
	    return dp[i][j] = Math.max(x,y);
	}
	public static int stoneGameVII(int[] v) {
	    int n = v.length;
	    int s = 0;
	    for(int x : v){
	        s+=x;
	    }
	    for(int i = 0; i < 1001; ++i) {
	        for(int j = 0; j < 1001; ++j) {
	        dp[i][j] = -1 ;
	        }
	    }
	    return helper(v,0,n-1,s);
	 }
	
	public static void main(String[] args) {
		int[] v = {7,90,5,1,100,10,10,2};
		System.out.print(stoneGameVII(v));
	}
}
