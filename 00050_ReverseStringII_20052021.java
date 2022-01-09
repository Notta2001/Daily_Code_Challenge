
public class ReverseStringII {
	public static String reverseStr(String s, int k) {
		char[] cs = s.toCharArray();
		for(int i = 0; i < cs.length; i += 2*k) {
			reverse(cs, i, Math.min(i + k - 1 , cs.length - 1));
		}
		// cannot use cs.toString();
		return new String(cs);
	}
	
	public static void reverse(char[]cs, int left, int right) {
		while(left < right) {
			char tmp = cs[left];
			cs[left++] = cs[right];
			cs[right--] = tmp;
		}
	}
	
	public static void main(String[] args) {
		String s1 = "abcdefgh";
		String s2 = "abcdefghiklmnopq";
		
		s1 = reverseStr(s1, 2);
		s2 = reverseStr(s2, 3);
		
		System.out.println(s1);
		System.out.println(s2);
	}
}


// https://leetcode.com/problems/reverse-string-ii/