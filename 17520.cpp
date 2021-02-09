#pragma warning(disable : 4996)
#include<iostream>
#include<cmath>
using namespace std;

int* toBin(int n, int num);

//십진수 -> 이진수 변환 함수
int* toBin(int n, int num) {
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {	//모두0으로 초기화
		arr[i] = 0;
	}
	for (int i = n-1; i >= 0; i--) {//이진수로 변환 후 배열에 저장
		arr[i] = num % 2;
		if (num < 2) break;
		num /= 2;
	}
	return arr;
}
//균형잡인 문자열 확인 함수
bool checkBalanced(int* bin, int n) {
	bool result;
	int cnt0 = 0; int cnt1 = 0; //cnt0 : 0의 갯수, cnt1 : 1의 갯수
	for (int i = 0; i < n; i++) {
		if (bin[i] == 0) cnt0++;
		else if (bin[i] == 1) cnt1++;
	}
	if ((cnt0 - cnt1) <= 1 && (cnt0 - cnt1) >= -1)
		return true;
	else
		return false;
}

int main() {
	int n; // n:자릿수 m : n 자릿수로 만들 수 있는 경우의 수 
	int m;
	int cnt = 0; // 균형잡힌 문자열의 갯수
	cin >> n;
	int* bin;
	m = (int)pow(2, n); // 경우의 수 2^n 개

	for (int i = 0; i < m; i++) {	//i = 0 ~ 2^(n) - 1 모든 경우
		bin = toBin(n, i);
		int fin;
		for (int j = 1; j <= n; j++) { // 한 경우에 대하여 균형잡힌 문자인지 확인
			fin = j;
			if (checkBalanced(bin, j)) continue;
			else {
				break;
			}
		}
		if (fin == n) cnt++;
	}
	cout << cnt % 16769023 << endl;

	return 0;
}

/*
#pragma warning (disable : 4996)
#include<iostream>

using namespace std;

int arr[100001];

int main() {

	int n;
	cin >> n;
	int i, j;
	arr[1]= 2;
	for (i = 2; i <= n; i++) {
		if ((i % 2) == 1)
			arr[i] = (arr[i - 1] * 2) % 16769023;
		else
			arr[i] = arr[i - 1];
	}
	cout << arr[n] << endl;
}
*/