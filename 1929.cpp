#include<iostream>
#include<math.h>
using namespace std;

int arr[1000001] = { 0 };

int main() {
	/*
	소수 구하기 -> 시간 줄여야함
	에라토스테네스의 체
	*/

	int n, m;

	cin >> n >> m;

	
	for (int i = n; i <= m; i++) {
		arr[i] = i;					//체크를 위해 배열에 수 저장
	}
	arr[1] = 0;						//1은 소수가 아니므로 0 set
	
	for (int i =2; i <= m; i++) {	
		for(int j = 2; i*j <= m ; j++) {	//i의 배수는 모두 0
			arr[i * j] = 0;					
		}
	}
	// 어떤 숫자의 배수도 아닌 숫자는 배열에 그대로 저장 되어 있음
	for (int i = n; i <=m; i++) {
		if (arr[i] !=0 ) {
			cout << arr[i] << '\n';
		}
	}

	return 0;
}