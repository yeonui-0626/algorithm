#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001];

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] + dp[i] > dp[i]) dp[i] = dp[i] + dp[i - 1];
	}

	int result = dp[0];
	for (int i = 1; i < n; i++) result = max(dp[i], result);

	cout << result;

	return 0;
}