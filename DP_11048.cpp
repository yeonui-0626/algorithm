#pragma warning (disable : 4996)
#include<iostream>

using namespace std;

int arr[1001][1001] = { 0 };
int candy[1001][1001] = { 0 };

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	candy[0][0] = arr[0][0];
	for (int j = 1; j < m; j++) {
		candy[0][j] = arr[0][j] + candy[0][j - 1];
	}
	for (int i = 1; i < n; i++) {
		candy[i][0] = arr[i][0] + candy[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			candy[i][j] = max(candy[i - 1][j] + arr[i][j], candy[i][j - 1] + arr[i][j]);
		}
	}

	int result = candy[n-1][m-1];
	cout << result << endl;

	return 0;
}