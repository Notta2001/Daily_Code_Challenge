
public class MinimumMovesToEqualArrayElementsII {
	public static int minMoves2(int[] nums) {
		int ans = 0;
		int n = nums.length;
		if(nums == null || n == 0) return ans;
		// We have two ways to sort an array
		// Method 1 :
		// Arrays.sort(nums);
		
		// Method 2 :		
		for(int i = 0; i< n-1; ++i) {
			for(int j = i+1; j < n; ++j) {
				if(nums[i] > nums[j]) {
					int tmp = nums[i];
					nums[i] = nums[j];
					nums[j] = tmp;
				}
			}
		}
		int medium_value = nums[n/2];
		
		for(int i = 0; i < n; ++i) {
			if(i > n/2) ans += nums[i] - medium_value;
			else ans += medium_value - nums[i];
			
			// Shorter way;
			// ans += Math.abs(medium_value - nums[i]);
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		int[] arr1 = {1, 2, 3};
		int[] arr2 = {1, 10, 2, 9};
		
		System.out.println(minMoves2(arr1));
		System.out.println(minMoves2(arr2));
	}
}
