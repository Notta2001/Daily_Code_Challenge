import java.util.Arrays;

public class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts {
	public static int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
		int width, height, maxWidth = 0, maxHeight = 0;
		int m = horizontalCuts.length;
		int n = verticalCuts.length;

		Arrays.sort(horizontalCuts);
		Arrays.sort(verticalCuts);
		
		for(int i = 0; i <= m; ++i) {
			if(i == 0) 
				width = horizontalCuts[i];
			else if(i == m) 
				width = h - horizontalCuts[i - 1];
			else 
				width = horizontalCuts[i] - horizontalCuts[i - 1];
			maxWidth = Math.max(maxWidth, width);
		}
		
		for(int j = 0; j <= n; ++j) {
			if(j == 0) 
				height = verticalCuts[j];
			else if(j == n) 
				height = w - verticalCuts[j - 1];
			else 
				height = verticalCuts[j] - verticalCuts[j - 1];
			maxHeight = Math.max(maxHeight, height);
		}
		
		return (int)((long)maxWidth * maxHeight % 1000000007);
	}
	
 	public static void main(String[] args) {
 		int[] horizontalCuts = {1, 3};
 		int[] verticalCuts = {1};
 		System.out.println(maxArea(5, 4, horizontalCuts, verticalCuts));
 	}
}
