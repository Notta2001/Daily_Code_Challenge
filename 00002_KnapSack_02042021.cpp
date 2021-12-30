#include<iostream>
#include<algorithm>
using namespace std;

int knapSack(const int* weights, const int* values, int n, int W) {
	int K[n + 1][W + 1];
	for (int i = 0; i <= n; ++i) {
		for (int w = 0; w <= W; ++w) {
			if (i == 0 || w == 0) {
				K[i][w] = 0;
			}
			else if (w < weights[i]) {
				K[i][w] = K[i - 1][w];
			}
			else
				K[i][w] = max(K[i - 1][w - weights[i]] + values[i], K[i - 1][w]);
		}
	}
	return K[n][W];
}

int main() {
	int weights[4] = { 1, 3, 4, 5 };
	int values[4] = { 1, 4, 5, 7 };
	cout << knapSack(weights, values, 4, 7);
}

