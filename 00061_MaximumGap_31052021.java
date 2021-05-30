import java.util.ArrayList;
import java.util.List;

public class MaximumGap {
	public static int maximumGap(int[] nums) {
		// example : [21, 9, 25, 3, 37, 43, 49, 29]
	    int n = nums.length;
	    if(n < 2) return 0;
	    int hi = 0, lo = Integer.MAX_VALUE, ans = 0;
	    for(int num : nums) {
	    	hi = Math.max(hi, num);
	    	lo = Math.min(lo, num);
	    }
	    // bucket_size = (49 - 3) / 7 = 7 is also the average distance between two elements
	    int bucket_size = Math.max((hi - lo) / (n - 1), 1);
	    // initialize buckets [3,10] [10,17] .... [45, 49] 
	    List<List<Integer>> buckets = new ArrayList<List<Integer>>();
	    // put each elements into its bucket
	    for(int i = (hi - lo) / bucket_size; i >= 0; --i) {
	    	buckets.add(new ArrayList<>());
	    }
	    for(int num : nums) {
	    	buckets.get((num - lo) / bucket_size).add(num);
	    }
	    int currhi = 0;
	    for(List<Integer> bucket : buckets) {
	    	if(bucket.isEmpty()) continue;
	    	int prevhi = currhi > 0 ? currhi : bucket.get(0), currlo = bucket.get(0);
	    	for(int num : bucket) {
	    		currhi = Math.max(currhi, num);
	    		currlo = Math.min(currlo, num);
	    	}
	    	ans = Math.max(ans, currlo - prevhi);
	    }
	    return ans;
	    
	    // Notes : All the elements within the bucket will have a gap < bucket size. Numbers falling inside the
	    //same bucket can have a maximum gap of bucket_size-1 so it will never give us a maximum gap. In order to 
	    //find a maximum gap, I need to find the maximum among distances between prevhi and curlow of two successive 
	    //buckets.
	    
	    // The problem requires us to do it in linear time with linear extra space.
	}
	
	public static void main(String[] args) {
		int[] arr = {1, 3, 6, 9};
		System.out.println(maximumGap(arr));
	}
}
