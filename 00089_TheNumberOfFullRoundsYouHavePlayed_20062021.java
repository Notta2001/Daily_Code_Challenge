
public class TheNumberOfFullRoundsYouHavePlayed {
	public static int numberOfRounds(String startTime, String finishTime) {
		int ans = 0;
		if(startTime == finishTime) return 0;
        int startHour = Integer.parseInt(startTime.substring(0,2));
        int startMinute = Integer.parseInt(startTime.substring(3));
        int finishHour = Integer.parseInt(finishTime.substring(0,2));
        int finishMinute = Integer.parseInt(finishTime.substring(3));
        if(startHour == finishHour && startMinute <= finishMinute) {
        	ans = rounds(startHour, startMinute, finishHour, finishMinute);
        }
        if(startHour > finishHour || (startHour == finishHour && startMinute > finishMinute)) {
        	ans = rounds(startHour, startMinute, 23, 60) + rounds(0, 0, finishHour, finishMinute);
        }
        if(startHour < finishHour) {
        	int ans1 = rounds(startHour, startMinute, startHour, 60);
        	int ans2 = rounds(startHour+1, 0, finishHour, finishMinute);
        	ans = ans1 + ans2;
        }
        return ans;
    }
	
	public static int rounds(int startHour, int startMinute, int finishHour, int finishMinute ) {
		//System.out.println(startHour + " " + startMinute + " " + finishHour + " " + finishMinute);
		int ans = 0;
        int start = startMinute;
        if(startMinute % 15 != 0){
            int period = startMinute/15;
    	    start = period*15 + 15;
        }
    	while(start + 15 <= finishMinute) {
    		ans += 1;
    		start += 15;
    	}
        //System.out.println(ans);
    	ans += (finishHour - startHour) * 4;
    	return ans;
	}
	
	public static void main(String[] args) {
		System.out.println(numberOfRounds("13:53","16:58"));
	}
}

//https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
