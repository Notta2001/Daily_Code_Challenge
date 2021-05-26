
public class PartitioningIntoMinimumNumberOfDeciBinaryNumbers {
	public static int minPartitions (String n) {
		int ans = -1;
		int length = n.length();
		if(length == 0 || n == null) return ans;

		for(int i = 0; i < length; ++i) {
			int cur = Character.getNumericValue(n.charAt(i));
			ans = Math.max(cur, ans);
		}
		return ans;
	}
	
	public static void main(String[] args) {
		String s1 = "27346209830709182346";
		System.out.print(minPartitions(s1));
	}
}
