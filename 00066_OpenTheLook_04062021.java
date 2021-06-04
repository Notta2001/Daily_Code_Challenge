import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class OpenTheLook {
	public static int openLock(String[] deadends, String target) {
        HashSet<String> dead_set = new HashSet<>(Arrays.asList(deadends));
        if (dead_set.contains("0000")) return -1;
        Queue<String> queue = new LinkedList<>();
        queue.add("0000");
        int count = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                String tmp = queue.remove();
                if (target.equals(tmp)) return count;
                char[] c = tmp.toCharArray();
                for (int j = 0; j < 4; j++) {
                    int i = c[j] - '0'; // we want to keep it as a initial state of c[j]
                    
                    c[j] = (char) ('0' + (i + 9) % 10);// rotate back
                    String s = new String(c);

                    if (!dead_set.contains(s)) {
                        queue.add(s);
                        dead_set.add(s);
                    }
                    c[j] = (char) ('0' + (i + 11) % 10);// rotate up
                    s = new String(c);

                    if (!dead_set.contains(s)) {
                        queue.add(s);
                        dead_set.add(s);
                    }
                    c[j] = (char) ('0' + i);  // return the initial state
                }
            }
            count++;
        }
        return -1;
    }
	
	public static void main(String[] args) {
		String[] deadends1 = {"0201","0101","0102","1212","2002"};
		System.out.println(openLock(deadends1, "0202"));
		
		String[] deadends2 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
		System.out.println(openLock(deadends2, "8888"));
	}
}
