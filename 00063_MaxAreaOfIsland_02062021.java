
public class MaxAreaOfIsland {
	public static int maxAreaOfIsland(int[][] grid) {
		int ans = 0;
		int n = grid.length;
		int m = grid[0].length;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++ j) {
				int curArea = area(n, m, i, j, grid);
				ans = (curArea > ans) ? curArea : ans;
			}
		}
		return ans;
	}
	
	private static int area(int n, int m, int i, int j, int[][] grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] < 1) return 0;
        grid[i][j] = 0;
        return 1 + area(n, m, i-1, j, grid) + area(n, m, i, j-1, grid) + area(n, m, i+1, j, grid) + area(n, m, i, j+1, grid);
    }
	
	public static void main(String[] args) {
		int[][] grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
		System.out.print(maxAreaOfIsland(grid));
	
	}
}
