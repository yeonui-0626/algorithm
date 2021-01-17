#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1001];
int arr_dp[1001];

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		arr_dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j] #include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1001];
int arr_dp[1001];

int main(void) {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		arr_dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j] && arr_dp[i] < arr_dp[j] + 1) {
				arr_dp[i] = arr_dp[j] + 1;
			}
		}
	}
	
	int result=0;
	for (int i = 1; i <=n; i++) {
		result = max(arr_dp[i],result);
	}

	cout << result;

	return 0;
}) {
				arr_dp[i] = arr_dp[j] + 1;
			}
		}
	}
	
	int result=0;
	for (int i = 1; i <=n; i++) {
		result = max(arr_dp[i],result);
	}

	cout << result;

	return 0;
}