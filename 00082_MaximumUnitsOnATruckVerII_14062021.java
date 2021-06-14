// more effectively than verI because it runs faster
public class MaximumUnitsOnATruckVerII {
	public static int maximumUnits(int[][] boxTypes, int truckSize) {
		int[] cs = new int[1001];
		for(int i = 0; i < boxTypes.length; ++i) {
			cs[boxTypes[i][1]] += boxTypes[i][0];
		}
		int total = 0;
		for(int i = 1000; i >= 0 && truckSize > 0; --i) {
			if(cs[i] != 0) {
				total += Math.min(truckSize, cs[i]) * i;
				truckSize -= cs[i];
			}
		}
		return total;
	}
	
	public static void main(String[] args) {
		int[][] boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
		int truckSize = 10;
		System.out.println(maximumUnits(boxTypes, truckSize));
	}
}
