#include<iostream>
#include<algorithm>

using namespace std;

int T[16];
int P[16];
int n;
int MAX = 0;	// 최대수익
int sum = 0;

void find(int next,int sum) {
	MAX = max(MAX, sum);
	for (int i = next; i <= n; i++) {
		if (i + T[i] - 1 > n) continue;
		find(i + T[i], sum + P[i]);
	}
	return;
}

int main() {
	// 퇴사 전, 남은 n 일
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	find(1,sum);

	cout << MAX << '\n';

	return 0;
}