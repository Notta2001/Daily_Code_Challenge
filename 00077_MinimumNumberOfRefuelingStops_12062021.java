import java.util.Comparator;
import java.util.PriorityQueue;

public class MinimumNumberOfRefuelingStops {
	public static int minRefuelStops(int target, int startFuel, int[][] stations) {
		Comparator<Integer> comparator = new Comparator<>() {
			public int compare(Integer i1, Integer i2) {
				return i2 - i1;
			}
		};
		
		PriorityQueue<Integer> pq = new PriorityQueue<>(comparator);
		
		int curr = startFuel;
		int i = 0;
		
		int stopCount = 0;
		
		while(curr < target) {
			while(i < stations.length && stations[i][0] <= curr) {
				pq.offer(stations[i][1]);
				i++;
			}
			
			if(pq.isEmpty()) {
				return -1;
			}
			
			curr += pq.poll();
			stopCount++;
		}
		return stopCount;
	}
	
	public static void main(String[] args) {
		int [][] stations = {{10, 60}, {20, 30}, {30, 60}, {60, 40}};
		System.out.println(minRefuelStops(100, 10, stations));
	}
}
