
public class NQueensII {
	
	public static int totalNQueens(int n) {
		int ans = helper(0, new int[n], new int[2*n], new int[2*n], n);
		return ans;
	}
	
	public static int helper(int index, int[] col, int[] hill, int[] dale, int n) {
		int ans = 0;
		if(index == n ) {
			return 1;
		}
		else {
			for(int i = 0; i < n; ++ i) {
				if(col[i] == 0 && hill[i + index] == 0 && dale[i - index + n] == 0) {
					col[i] = 1;
					hill[i + index] = 1;
					dale[i - index + n] = 1;
					
					ans += helper(index + 1, col, hill, dale, n);
					
					col[i] = 0;
					hill[i + index] = 0;
					dale[i - index + n] = 0;
				}
			}
		}
		return ans;
	}
	
	public static void main(String[] args) {
		System.out.print(totalNQueens(8));
	}
}
