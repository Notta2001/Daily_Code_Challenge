public class MaximumUnitsOnATruck {
	public static int maximumUnits(int[][] boxTypes, int truckSize) {
		int numBox = boxTypes.length;
		int curUnits = 0;
		for(int i = 0; i < numBox - 1; ++i) {
			for(int j = i + 1; j < numBox; ++j) {
				if(boxTypes[j][1] > boxTypes[i][1]) {
					int[] cur = boxTypes[i];
					boxTypes[i] = boxTypes[j];
					boxTypes[j] = cur;
				}
			}
		}
		
		for(int i = 0; i < numBox; ++i) {
			if(truckSize >=boxTypes[i][0]) {
				curUnits += boxTypes[i][0] * boxTypes[i][1];
				truckSize -= boxTypes[i][0];
			}else {
				curUnits += truckSize * boxTypes[i][1];
				truckSize = 0;
			}
			System.out.println(truckSize + " " + curUnits);
			if(truckSize == 0) return curUnits;
		}
		return curUnits;
	}
	
	public static void main(String[] args) {
		int[][] boxTypes = {{1, 3}, {2, 2}, {3, 1}};
		int truckSize = 4;
		System.out.println(maximumUnits(boxTypes, truckSize));
	}
}
