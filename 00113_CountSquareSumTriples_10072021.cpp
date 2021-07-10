#include<iostream>
#include<math.h>
using namespace std;

class Solution {
	public :
		int countTriplets (int n) {
			int count = 0;
			int a, b, c;
			a = b = c = 1;
			int sum = 0;
			
			for (a = 1; a <= n; ++ a){ // 1 <= a <= n
				for(b = a; b <= n; ++b){ // 1 <= a <= b <= n
					sum = a * a + b * b; // a^2 + b^2 = c^2
					c = sqrt(sum);
					if (c * c == sum && b <= c && c<= n) { // check 1 <= a <= b <= c <= n
						count += 2;
						cout << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
					}
				}
			}
			return count;
		}
};

int main () {
	Solution obj;
	cout << obj.countTriplets(12);
	return 1;
}
