public class MergeTripletsToFormTargetTriplet {
	public static boolean mergeTriplets(int[][] triplets, int[] target) {
		int n = triplets.length;
		boolean[] state = {false, false, false};
		for(int i = 0; i < n; ++i) {
			if(triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2])
				state[0] = true;
			if(triplets[i][0] <= target[0] && triplets[i][1] == target[1] && triplets[i][2] <= target[2])
				state[1] = true;
			if(triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] == target[2])
				state[2] = true;
		}
		return state[1]&&state[2]&&state[0];
	}
	
	public static void main(String[] args) {
		int[][] triplets1 = {{3, 4, 5}, {4, 5, 6}};
		int[] target1 = {3, 2, 5};
		System.out.println(mergeTriplets(triplets1, target1));
		int[][] triplets2 = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
		int[] target2 = {2, 7, 5};
		System.out.println(mergeTriplets(triplets2, target2));
	}
}
