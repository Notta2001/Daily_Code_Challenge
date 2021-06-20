public class LargestOddNumberInString {
	public static String largestOddNumber(String num) {
		String ans = "";
		int lastOdd = 0	;
		for(int i = num.length()- 1; i >= 0; --i) {
			if((num.charAt(i) - '0') % 2 == 1) {
				lastOdd = i;
				break;
			}
		}
		ans = num.substring(0,lastOdd+1);
		return ans;
    }
	
	public static void main(String[] args) {
		System.out.println(largestOddNumber("23458752"));
	}
}
