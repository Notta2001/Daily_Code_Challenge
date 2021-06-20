public class SwimInRisingWater {
	 public static int N;
	 public static boolean[][] visited;
	 public static int dx[] = {1, -1, 0, 0};
	 public static int dy[] = {0, 0, 1, -1};
	 public static int m;
	    
	 public static boolean isValid(int x, int y){
	    if(x==N || x<0 || y==N || y<0)
	        return false;
	    if(visited[x][y])
	        return false;
	    return true;
	 }
	    
	 public static boolean dfs(int x, int y, int[][] grid, int time){
	    visited[x][y] = true;
	    if(x==N-1 && y==N-1 && time<=m)
	        return true;
	    if(time > m)
	        return false;
	    for(int i=0; i<4; i++){
	        if(isValid(x+dx[i], y+dy[i])){
	            int now = Math.max(time, grid[x+dx[i]][y+dy[i]]);
	            if(dfs(x+dx[i], y+dy[i], grid, now))
	               return true;
	        }
	                
	    }
	    return false;
	 
	 }
	    
	 public static  int swimInWater(int[][] grid) {
	    N = grid.length;
	    int l = -1, r = N*N;
	    while(l+1 < r){
	        m = (l+r)/2;
	        visited = new boolean[N][N];
	        if(dfs(0, 0, grid, grid[0][0]))
	            r = m;
	        else
	            l = m;
	    }
	    return r;
	}
	
	public static void main(String[] args) {
		int[][] arr = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
		System.out.println(swimInWater(arr));
	}
}
//https://leetcode.com/problems/swim-in-rising-water/
