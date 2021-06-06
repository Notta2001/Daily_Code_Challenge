import java.util.Arrays;

public class ReductionOperationsToMakeTheArrayElementsEqual {
	public static int reductionOperations(int[] nums) {
        int ans = 0;
        int count = 0;
        int len = nums.length;
        if(len == 1) return 0;
        Arrays.sort(nums);
        for(int i = 1; i < len; ++i) {
        	if(nums[i] == nums[i-1]) {
        		ans += count;
        	}
        	else {
        		count += 1;
        		ans += count;
        	}
        }
        return ans;
    }
	
	public static void main(String[] args) {
		int[] nums = {1, 1, 2, 2, 3};
		System.out.println(reductionOperations(nums));
	}
}
