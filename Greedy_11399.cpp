#include<iostream>
#include<algorithm>

using namespace std;

int n, sum;
int arr[1000];

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//오름차순 정렬 ※인덱스 주의※
	sort(arr, arr + n);

	sum = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i-1];	// 각 사람 마다 기다리는 시간 
		sum += arr[i];	// 기다린 시간의 총합
	}
	
	cout << sum << endl;

	return 0;
}