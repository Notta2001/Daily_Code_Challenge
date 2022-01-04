public class MaximumPointsYouCanObtainFromCard {
	public static int maxScore(int[] cardPoints, int k) {
		int max;
		int res = 0;
		int left = 0;
		int right = k - 1;
		
		for(int i = 0; i < k; ++i) {
			res += cardPoints[i];
		}
		
		max = res; 
		
		while(right > 0) {
			res = res - cardPoints[right--] + cardPoints[left-- + cardPoints.length - 1];
			if(res > max) max = res;
 		}
		
		return max;
	}
	
	public static void main(String[] args) {
		int init1[] = {1, 2, 3, 4, 5, 6, 1};
		int init2[] = {1, 79, 80, 1, 1, 1, 200, 1};
		
		System.out.println(maxScore(init1, 3));
		System.out.println(maxScore(init2, 4));
	}
}

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/