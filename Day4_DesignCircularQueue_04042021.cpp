#include<iostream>
using namespace std;

class MyCircularQueue{
	public :
		int arr[1001];
		int size;
		int headIndex = -1, tailIndex = -1;
		int count = 0; // current number of elements
		
		MyCircularQueue(int k){
			size = k;
			return;
		}
		
		bool enQueue(int value){
			if(isFull() == true){
				return false;
			}
			
			tailIndex ++;
			
			if(tailIndex == size){
				tailIndex = 0;
			}
			
			arr[tailIndex] = value;
			
			if(isEmpty() == true){
				headIndex = tailIndex;
			}
			
			count ++;
			return true;
		}
		
		bool deQueue(){
			if(isEmpty() == true){
				return false;
			}
			
			headIndex ++;
			
			if(headIndex == size){
				headIndex = 0;
			}
			
			count --;
			return true;
		}
		
		int Front(){
			return isEmpty() ? -1 : arr[headIndex];
		}
		
		int Rear(){
			return isEmpty() ? -1 : arr[tailIndex];
		}
		
		bool isEmpty(){
			return count <= 0 ? true : false;
		}
		
		bool isFull(){
			return count >= size ? true : false;
		}
		
};

int main(){
	MyCircularQueue * obj = new MyCircularQueue(3);
	
	cout << obj->enQueue(1);
	cout << obj->enQueue(2);
	cout << obj->enQueue(3);
	cout << obj->enQueue(4);
	cout << obj->Rear();
	cout << obj->isFull();
	cout << obj->deQueue();
	cout << obj->enQueue(4);
	couast << obj->Front();
	
	return 0;
}
