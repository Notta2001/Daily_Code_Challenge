#include<iostream>
#include<set>
using namespace std;

class MedianFinder {
	public :
		multiset<int> ms;
		multiset<int>:: iterator it1, it2;
		
		MedianFinder () {
			
		}
		
		void addNum (int num) {
			int n = ms.size();
			ms.insert(num);
			if (n == 0) 
				it1 = it2 = ms.begin();
			else if (n % 2 == 1) {
				if (num < *it1) {
					it1 --;
				}
				else it2 ++;
			} 
			else {
				if (*it1 < num && *it2 > num) {
					it1 ++;
					it2 --;
				}
				else if (num >= *it2) {
					it1 ++;
				}
				else {
					it2 --;
					it1 = it2;
				}
			}
			cout << *it1 << " " << *it2 << endl;
		}
		
		double findMedian() {
			return (*it1 + (*it2)) * 1.0 / 2.0;
		}
};

int main () {
	MedianFinder *obj = new MedianFinder ();
	obj->addNum(6);
	obj->addNum(10);
	obj->addNum(2);
	obj->addNum(6);
	obj->addNum(5);
	cout << obj->findMedian() << endl;
	obj->addNum(3);
	cout << obj->findMedian() << endl;
	
	return 1;
	
}

//https://leetcode.com/problems/find-median-from-data-stream/
