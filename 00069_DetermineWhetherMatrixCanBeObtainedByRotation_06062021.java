public class DetermineWhetherMatrixCanBeObtainedByRotation {
    public static boolean findRotation(int[][] mat, int[][] target) {
    	if(equal(mat, target)) return true;
    	for(int i = 0; i < 3; ++i) {
    		int[][] rotated = rotate(mat);
    		mat = rotated;
    		if(equal(rotated, target)) return true;
    	}
    	return false;   	
    }
    
    public static int[][] rotate(int[][] mat){
    	int len = mat.length;
    	int[][] ans = new int[len][len];
    	for(int i = 0; i < len; ++i) {
    		for(int j = 0; j < len; ++j) {
    			ans[j][len-1-i] = mat[i][j];
    		}
    	}
    	return ans;
    }
    
    public static boolean equal(int[][] rotated, int[][] target) {
    	int len = rotated.length;
    	for(int i = 0; i < len; ++i) {
    		for(int j = 0; j < len; ++j) {
    			if(rotated[i][j] != target[i][j]) return false;
    		}
    	}
    	return true;
    }
    
    public static void main(String[] args) {
    	int[][] mat = {{0,0,0},{0,1,0},{1,1,1}};
    	int[][] target = {{1,1,1},{0,1,0},{0,0,0}};
    	System.out.println(findRotation(mat, target));
    }
}
