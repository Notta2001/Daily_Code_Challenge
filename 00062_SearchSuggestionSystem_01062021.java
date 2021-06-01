import java.util.*;

public class SearchSuggestionSystem {
		public static List<List<String>> suggestedProducts(String[] P, String S){
			Arrays.sort(P);
			List<List<String>> ans = new ArrayList<List<String>>();
			int left = 0, right = P.length - 1;
			
			for(int i = 0; i < S.length(); ++i) {
				List<String> res = new ArrayList<>();
				char c = S.charAt(i);
				while(left <= right && (P[left].length() == i || P[left].charAt(i) <c)) left ++;
				while(left <= right && (P[right].length() == i || P[right].charAt(i) > c)) right --;
				for(int j = 0; j < 3 && left + j <= right; ++j) {
					res.add(P[left + j]);
				}
				ans.add(res);
			}
			return ans;
		}
	
	public static void printAns(List<List<String>> ans) {
		for(List<String> list : ans) {
			System.out.print("[");
			for(String word : list) {
				System.out.print(" " + word + " ");
			}
			System.out.print("]" + "\n");
		}
	}
	
	public static void main(String[] args) {
		String[] products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
		String search_word = "mouse";
		List<List<String>> ans = suggestedProducts(products, search_word);
		printAns(ans);
	}
}
