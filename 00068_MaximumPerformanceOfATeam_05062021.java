import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class MaximumPerformanceOfATeam {
	public static int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        int[][] engineers = new int[n][];
        for (int i = 0; i < n; i++) {
            engineers[i] = new int[]{efficiency[i], speed[i]};
            System.out.println(engineers[i][0] + " " + engineers[i][1]);
        }
        Arrays.sort(engineers, (int[] a, int[] b) -> (b[0] - a[0]));
        System.out.println(" ");
        for (int i = 0; i < n; i++) {
            System.out.println(engineers[i][0] + " " + engineers[i][1]);
        }
        Queue<Integer> pq = new PriorityQueue<>();
        long sum = 0, res = 0;
        for (int[] engineer : engineers) {
            pq.offer(engineer[1]);
            sum += engineer[1];
            if (pq.size() > k) {
                sum -= pq.poll();
            }
            res = Math.max(res, sum * engineer[0]);
        }
        
        return (int) (res % (long) (1e9 + 7));
    }
	
	public static void main(String[] args) {
		int n = 6;
		int[] speed = {2,10,3,1,5,8};
		int[] efficiency = {5,4,3,9,7,2};
		int k = 2;
		System.out.println(maxPerformance(n, speed, efficiency, k));
	}
}
