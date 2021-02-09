#pragma warning(disable : 4996)
#include<iostream>
#include<cmath>
using namespace std;

int* toBin(int n, int num);

//������ -> ������ ��ȯ �Լ�
int* toBin(int n, int num) {
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {	//���0���� �ʱ�ȭ
		arr[i] = 0;
	}
	for (int i = n-1; i >= 0; i--) {//�������� ��ȯ �� �迭�� ����
		arr[i] = num % 2;
		if (num < 2) break;
		num /= 2;
	}
	return arr;
}
//�������� ���ڿ� Ȯ�� �Լ�
bool checkBalanced(int* bin, int n) {
	bool result;
	int cnt0 = 0; int cnt1 = 0; //cnt0 : 0�� ����, cnt1 : 1�� ����
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
	int n; // n:�ڸ��� m : n �ڸ����� ���� �� �ִ� ����� �� 
	int m;
	int cnt = 0; // �������� ���ڿ��� ����
	cin >> n;
	int* bin;
	m = (int)pow(2, n); // ����� �� 2^n ��

	for (int i = 0; i < m; i++) {	//i = 0 ~ 2^(n) - 1 ��� ���
		bin = toBin(n, i);
		int fin;
		for (int j = 1; j <= n; j++) { // �� ��쿡 ���Ͽ� �������� �������� Ȯ��
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