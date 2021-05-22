import java.util.*;


public class NQueens {
	public static List<List<String>> solveQueen(int n){
		List<List<String>> list = new ArrayList<List<String>>();
		// solve problem
		solve(list, new int[n], new int[n], new int[n*2], new int[n*2], 0, n);
		return list;
	}
	
	public static void solve(List<List<String>> list, int[] row, int[] col, int[] hill, int[] dale, int index, int n) {
		if(index == n) {
			List<String> nList = new ArrayList<String>();
			for(int i : row) {
				StringBuilder sb = new StringBuilder();
				for(int j = 0; j < n; ++j) {
					if(j == i) sb.append('Q');
					else sb.append('.');
				}
				nList.add(sb.toString());
			}
			list.add(nList);
		}
		
		for(int i = 0; i < n; ++i) {
			if(col[i] == 0 && hill[index + i] == 0 && dale[index-i+n] == 0) {
				col[i] = 1;
				hill[index + i] = 1;
				dale[index - i + n] = 1;
				
				row[index] = i;
				
				solve(list, row, col, hill, dale, index+1, n);
				
				col[i] = 0;
				hill[index + i] = 0;
				dale[index - i + n] = 0;
			}
		}
	}
	
	public static void print(List<List<String>> ans) {
		System.out.println("123");
		for(int i = 0; i < ans.size(); ++i) {
			System.out.print("[");
			for(int j = 0; j < ans.get(i).size(); ++j) {
				System.out.print("[" + ans.get(i).get(j) + "]");
			}
			System.out.print("]");
			System.out.println("");
		}
	}
	
	public static void main(String[] args) {
		List<List<String>> ans = solveQueen(4);
		print(ans);
	}
}

/*
 * Note : row[n], col[n], hill[2*n], dale[2*n]
 * hill ~ index + i, dale ~ index - i + n
 * we run index for each row, suppose n = 4
 * 
 * hill      col       dale      -
 * -         index     -         -
 * dale      col       hill      -
 * -         col       -         hill
 */
    
