import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindTheShortestSuperstring {
	public static String merge(String s1, String s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		
		int overlapped1 = 0;
		int overlapped2 = 0;
		for(int len = 1; len <= len1 && len <= len2; ++ len) {
			if(s1.substring(len1 - len).equals(s2.substring(0, len))) {
				overlapped1 = len;
			}
			if(s2.substring(len2 - len).equals(s1.substring(0, len))) {
				overlapped2 = len;
			}
		}
		
		if(overlapped1 > overlapped2) {
			return s2 + s1.substring(0, overlapped1);
		}
		else return s1 + s2.substring(0, overlapped2);
	}
	
	public static String shortestSuperstring(String[] A) {
		List<String> list = new ArrayList(Arrays.asList(A));
		while(true) {
			int n = list.size();
			if(n == 1) break;
			
			int maxLength = -1;
			int index1 = 0;
			int index2 = 0;
			String newStr = "";
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					String s1 = list.get(i);
					String s2 = list.get(j);
					String merged = merge(s1, s2);
					
					int saved = s1.length() + s2.length() - merged.length();
					if(saved > maxLength) {
						maxLength = saved;
						index1 = i;
						index2 = j;
						newStr = merged;
					}
				}
			}
			String str1 = list.get(index1);
			String str2 = list.get(index2);
			list.remove(str1);
			list.remove(str2);
			list.add(newStr);
		}
		return list.get(0);
	}
	
	public static void main(String[] args) {
		String[] init = {"catg","ctaagt","gcta","ttca","atgcatc"};
		String res = shortestSuperstring(init);
		System.out.print(res);
	}
}
