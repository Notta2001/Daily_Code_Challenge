import java.util.BitSet;

public class MaximumProductOfWordLengths {
	public static int maxProduct(String[] words) {
		int best = 0;
        int[] bitsets = new int[words.length];
        for (int i = 0; i < words.length; i++) {
            int wlen = words[i].length(), bitset = 0;
            for (int j = 0; j < wlen; j++) {
            	bitset |= 1 << (words[i].charAt(j) - 'a');	// OR bit use to make 110011011
            	System.out.println(bitset);
            }
            System.out.println();
            for (int j = 0; j < i; j++)
                if ((bitsets[j] & bitset) == 0)
                    best = Math.max(best, wlen * words[j].length());
            // reverse the way we often compare in array
            bitsets[i] = bitset;
        }
        return best;
	}
	
	public static int maxProduct2(String[] words) {
	       BitSet[] bitSets = new BitSet[words.length];
	        for (int i = 0; i < words.length; i++) {
	            bitSets[i] = new BitSet(26);
	            for (char c : words[i].toCharArray()) {
	                bitSets[i].set(c - 'a'); // make the element in position i to 1
	            }
	            System.out.println(bitSets[i]);
	        }
	        int best = 0;
	        for (int i = 0; i < words.length; i++) {
	            for (int j = i + 1; j < words.length; j++) {
	                if(!bitSets[i].intersects(bitSets[j])){
	                    best = Math.max(best, words[i].length() * words[j].length());
	                }
	            }
	        }
	        return best;  
	    }
	public static void main(String[] args) {
		String[] words = {"a","aa","aaa","aaaa"};
		System.out.println(maxProduct(words));
		String[] words2 = {"abcw","baz","foo","bar","xtfn","abcdef"};
		System.out.println(maxProduct2(words2));
	}
}
