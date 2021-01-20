#include<iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];
string str = "Goldbach's conjecture is wrong.";

int find(int num) {
	for (int i = 2; i <= num; i++) {
		if (arr[i] && arr[num - i]) {	//�Ѵ� Ȧ�� �Ҽ� �̸� 
			printf("%d = %d + %d\n", num, i, num - i);
			return 1;
		}
	}
	return 0;
}

int main() {

	std::cin.tie(NULL);
	std::ios::sync_with_stdio(0);

	/*		���� �Ҽ��� ���߸���.		*/
	fill_n(arr, MAX, 1);

	arr[2] = 0;
	for (int i = 2; i <= MAX; i++) {
		for (int j = 2; i * j <= MAX; j++) {
			arr[i * j] = 0;	// �Ҽ��� �ƴϸ� 0
		}
	}
	//-----------------------------------//
	int num;
	cin >> num;

	while (num) {
		if (!find(num)) {
			cout << str << '\n';
		}
		cin >> num;
	}

	return 0;
}