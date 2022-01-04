
public class CountPrimes {
	public static int countPrimes(int n) {
		boolean[] isPrime = new boolean[n];
		for(int i = 2; i < n; ++i) {
			isPrime[i] = true;
		}
		// Loop's ending condition is i*i < n instead of i < sqrt(n)
		// to avoid repeated calling an expensive function sqrt()
		for(int i = 2; i * i < n; ++i) {
			if(!isPrime[i]) continue;
			for(int j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
		int count = 0;
		for(int i = 2; i < n; ++ i) {
			if(isPrime[i]) count ++;
		}
		return count;
	}
	
	public static void main(String[] args) {
		int n1 = 54643;
		int n2 = 21;
		System.out.println(countPrimes(n1));
		System.out.println(countPrimes(n2));
	}
}

// https://leetcode.com/problems/count-primes/