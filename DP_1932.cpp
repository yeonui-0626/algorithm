#pragma warning(disable : 4996)
#include<iostream>

using namespace std;

int Max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
int arr[501][501] = { 0 };
int sum[501][501] = { 0 };

int main() {

	int k, result = 0;
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	sum[0][0] = arr[0][0];
	for (int i = 1; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum[i][j] = sum[i - 1][0] + arr[i][j];
			}
			else if (j == i) {
				sum[i][j] = sum[i - 1][j - 1] + arr[i][j];
			}
			else {
				sum[i][j] = Max(sum[i - 1][j - 1], sum[i - 1][j]) + arr[i][j];
			}
		}
	}

	for (int i = 0; i < k; i++) {
		result = Max(result, sum[k - 1][i]);
	}

	cout << result << endl;
	return 0;
}