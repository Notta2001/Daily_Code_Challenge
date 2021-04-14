#include<iostream>
using namespace std;
const int MAX = 100;

int n, c[MAX][MAX]; //so thanh phi va ma tran chi phi di lai
int cmin = INT_MAX; //chi phi di lai lon nhat giua cac thanh pho khac nhau
int best = INT_MAX; //tong chi phi nho nhat can tim, ban dau dat la gia tri INT_MAX = 2^31-1
int curr; //tong chi phi cho toi thoi diem hien tai
int mark[MAX]; //mang danh dau nhung thanh pho da di
int x[MAX]; //luu giu cac thanh pho da di

//Nhap cac du lieu dau vao
void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

void TRY(int k) {
    for (int i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            x[k] = i;
             curr += c[x[k - 1]][i];
            mark[i] = 1;
            if(k == n){
            	if(curr + c[x[k]][1] < best) best = curr + c[x[k]][1];
			}
			else if(curr + cmin*(n-k+1) < best) TRY(k+1);
			curr -= c[x[k - 1]][i];
			mark[i] = 0;
        }
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
