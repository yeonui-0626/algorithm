#include<iostream>
#include<algorithm>

using namespace std;

int n, sum;
int arr[1000];

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//�������� ���� ���ε��� ���ǡ�
	sort(arr, arr + n);

	sum = arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i-1];	// �� ��� ���� ��ٸ��� �ð� 
		sum += arr[i];	// ��ٸ� �ð��� ����
	}
	
	cout << sum << endl;

	return 0;
}