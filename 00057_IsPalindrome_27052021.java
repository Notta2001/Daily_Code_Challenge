
public class IsPalindrome {
	public static boolean isPalindrome(int x) {
		if(x < 0) return false;
		if(x == 0) return true;
		int cur = x, reversal = 0;
		while(cur > 0) {
			reversal = reversal * 10 + cur%10;
			cur /= 10;
		}
		return reversal == x;
	}
	
	public static void main(String[] args) {
		int a1 = 123454321;
		int a2 = 235564356;
		int a3 = -32534;
		int a4 = 0;
		
		System.out.println(isPalindrome(a1));
		System.out.println(isPalindrome(a2));
		System.out.println(isPalindrome(a3));
		System.out.println(isPalindrome(a4));
	}
}
