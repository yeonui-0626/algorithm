#include<iostream>
#include<math.h>
using namespace std;

int arr[1000001] = { 0 };

int main() {
	/*
	�Ҽ� ���ϱ� -> �ð� �ٿ�����
	�����佺�׳׽��� ü
	*/

	int n, m;

	cin >> n >> m;

	
	for (int i = n; i <= m; i++) {
		arr[i] = i;					//üũ�� ���� �迭�� �� ����
	}
	arr[1] = 0;						//1�� �Ҽ��� �ƴϹǷ� 0 set
	
	for (int i =2; i <= m; i++) {	
		for(int j = 2; i*j <= m ; j++) {	//i�� ����� ��� 0
			arr[i * j] = 0;					
		}
	}
	// � ������ ����� �ƴ� ���ڴ� �迭�� �״�� ���� �Ǿ� ����
	for (int i = n; i <=m; i++) {
		if (arr[i] !=0 ) {
			cout << arr[i] << '\n';
		}
	}

	return 0;
}