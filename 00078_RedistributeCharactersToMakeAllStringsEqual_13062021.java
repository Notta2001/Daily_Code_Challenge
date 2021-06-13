public class RedistributeCharactersToMakeAllStringsEqual {
	public static boolean makeEqual(String[] words) {
		int[] characters = new int[27];
		int len = words.length;
		if(len == 1) return true;
		for(int i = 0; i < len; ++i) {
			for(int j = 0; j < words[i].length(); ++j) {
				characters[words[i].charAt(j) - 'a'] ++;
			}
		}
		for(int i = 0; i < 27; ++i) {
			if(characters[i] % len != 0) return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		String[] words = {"abc","aabc","bc"};
		System.out.println(makeEqual(words));
	}
}
