#pragma warnning(disable : 4996)
#include<iostream>

using namespace std;

int main(){

	int n; 
	cin >> n;
	int p[1000];
	int pay[1000] = { 0 };
	for (int i = 1 ; i <= n; i++)	cin >> p[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			pay[i] = max(pay[i], pay[i - j] + p[j]);
		}
	}

	int result = pay[n];
	cout << result << endl;
	return 0;

}