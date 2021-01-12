//9095 1,2,3 ´õÇÏ±â
#include<iostream>
using namespace std;
int main() {

	int t, n;
	int arr[11];
	int result;
	arr[1] = 1; // 1
	arr[2] = 2; // 1+1, 2
	arr[3] = 4; // 1+1+1, 2+1,1+2, 3
	
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	cin >> t;

	while (t>0) {

		cin >> n;
		result = arr[n];
		cout << result << endl;

		t--;
	}

	return 0;

}