import java.util.HashSet;
import java.util.Set;

public class MaximumErasureValue {
	public static int maximumUniqueSubarray(int[] nums) {
		Set<Integer> set = new HashSet<>();
		int runningSum = 0;
		int maxSum = 0;
		int start = 0;
		int i = 0;
		while(i < nums.length) {
			int curInt = nums[i];
			if(!set.contains(curInt)) {
				set.add(curInt);
				runningSum += curInt;
				maxSum = Math.max(maxSum, runningSum);
				i++;
			}
			else {
				set.remove(nums[start]);
				runningSum -= nums[start];
				start ++;
			}
		}
		return maxSum;
	}
	
	public static void main(String[] args) {
		int[] arr1 = {5, 2, 1, 2, 5, 2, 1, 2, 5};  //[5, 2, 1] or [1, 2, 5]
		int[] arr2 = {2, 5, 3, 4, 1}; //[2, 5, 3, 4, 1]
		
		System.out.println(maximumUniqueSubarray(arr1));
		System.out.println(maximumUniqueSubarray(arr2));
	}
}
