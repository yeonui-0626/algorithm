#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int dp[1025][1025];

int main() {
	/*
	* 백준 11660
	* 구간 합 구하기5
	* DP
	*/
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;		// n x n 배열, m번 합을 구해야함
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] = dp[i][j] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		int result = 0;
		cin >> x1 >> y1 >> x2 >> y2;
	
		for (int x = x1; x <= x2; x++) {
			result += dp[x][y2] - dp[x][y1 - 1];
		}
		
		cout << result << '\n';
	}
	return 0;
}