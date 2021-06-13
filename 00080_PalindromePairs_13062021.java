import java.util.ArrayList;
import java.util.List;

public class PalindromePairs {
	public static List< List<Integer> > palindromePairs(String[] words){
		List<List<Integer> > ans = new ArrayList<List<Integer> >();
		int len = words.length;
		for(int i = 0; i < len - 1; ++i) {
			for(int j = i + 1; j < len; ++j) {
				String str1 = words[i] + words[j];
				String str2 = words[j] + words[i];
				if(isPalindrome(str1)) {
					List<Integer> newList = new ArrayList<Integer>();
					newList.add(i);
					newList.add(j);
					ans.add(newList);
				}
				if(isPalindrome(str2)) {
					List<Integer> newList = new ArrayList<Integer>();
					newList.add(j);
					newList.add(i);
					ans.add(newList);
				}
			}
		}
		
		return ans;
	}
	
	public static boolean isPalindrome(String word) {
		int len = word.length();
		if(len <= 1) return true;
		for(int i = 0; 2*i <= len + 1; ++i) {
			if(word.charAt(i) != word.charAt(len-1-i)) return false;
		}
		return true;
	}
	
	public static void printList(List<List<Integer>> ans) {
		System.out.print("[");
		for(int i = 0; i < ans.size(); ++i) {
			System.out.print("[");
			for(int j = 0; j < ans.get(i).size(); ++j) {
				System.out.print(" " + ans.get(i).get(j));
			}
			System.out.print("]");
		}
		System.out.print("]");
	}
	
	public static void main(String[] args) {
		String[] words = {"abcd","dcba","lls","s","sssll"};
		List<List<Integer>> ans = palindromePairs(words);
		printList(ans);
	}
	
	
}
