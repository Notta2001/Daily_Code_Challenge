
public class ToLowerCase {
	public static String toLowerCase(String s) {
		int n = s.length();
		char[] ch = new char[n];
		if(s == null || n == 0) return s;
		
		for(int i = 0; i < n; ++ i) {
			ch[i] = s.charAt(i);
			if(ch[i] >= 65 && ch[i] <= 92 ) {
				ch[i] += 32;
			}
		}
		return new String(ch);
		
		// easier way : just return s.toLowerCase();
	}
	
	public static void main(String[] args) {
		String a = "Hello Thang Doan";
		String b = toLowerCase(a);
		System.out.print(b);
	}
}
