#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int arr[501] = { 0 };
int del1[501] = { 0 };
int del2[501] = { 0 };
int main() {

	int t;
	cin >> t;
	int i, j;
	int index;
	for (i = 1; i <= t; i++) {
		cin >> index;
		cin >> arr[index];
	}
	int cnt = 1;
	for (i = 2; i <= 500; i++) {
		if (arr[i] > 0) {
			cnt++;
			for (j = 1; j < i; j++) {
				if (arr[i] < arr[j])
					del1[j] += 1;
			}
		}
		if (cnt == t) break;
	}
	cnt = 0;
	int del_line1 =0;
	for (i = 1; i <= 500; i++) {
		if (arr[i] > 0) {
			cnt++;
			if (del1[i] > 0) del_line1++;
		}
		if (cnt == t) break;
	}
	
	cnt = 1;
	for (i = 2; i <=500; i++) {
		if (arr[i] > 0) {
			cnt++;
			for (j = 1; j < i; j++) {
				if (arr[i] < arr[j])
					del2[i] += 1;
			}
		}
		if (cnt == t) break;
	}
	cnt = 0;
	int del_line2 = 0;
	for (i = 1; i <= 500; i++) {
		if (arr[i] > 0) {
			cnt++;
			if (del2[i] > 0) del_line2++;
		}
		if (cnt == t) break;
	}

	int result;
	if (del_line1 > del_line2) result = del_line2;
	else result = del_line1; 

	cout << result<< endl;

	return 0;
}