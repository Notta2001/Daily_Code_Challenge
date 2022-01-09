
public class validNumber {
	public static boolean isNumber(String s) {
		int len = s.length();
		int i = 0, e = len - 1;
		
		// check if s if formed with all whitespace 
		while(i <= e && Character.isWhitespace(s.charAt(i))) i++;
		if(i > len-1) return false;
		
		while(e >= i && Character.isWhitespace(s.charAt(e))) e--;
		
		//skip leading +/-
		if(s.charAt(i) == '+' || s.charAt(i) == '-') i++;
		boolean num = false; // is a digit
		boolean dot = false; // is a dot
		boolean exp = false; // is a 'e' or 'E'
		while(i <= e) {
			char c = s.charAt(i);
			if(Character.isDigit(c)) {
				num = true;
			}
			else if(c == '.') {
				if(exp || dot) return false; // cannot .e, e. ,.. ,....and cannot have . after e or E or .
				dot = true;
			}
			else if(c == 'e' || c == 'E') {
				if(exp || num == false) return false; // can not ee, eE, Ee, EE, .e, .E,... and cannot have e after e, need a digit after it
				exp = true;
				num = false;
			}
			else if(c == '+' || c == '-') {
				if(s.charAt(i-1) != 'e' && s.charAt(i-1) != 'E') {
					return false;
				}
			}
			else {
				return false;
			}
			i++;
		}
		return num; //9. is okay
	}
	
	public static void main(String[] args) {
		String s1 = "-90E3";
		String s2 = "3e+7";
		String s3 = "99e2.5";
		String s4 = "--6";
		System.out.println(isNumber(s1));
		System.out.println(isNumber(s2));
		System.out.println(isNumber(s3));
		System.out.println(isNumber(s4));
	}
}

// https://leetcode.com/problems/valid-number/