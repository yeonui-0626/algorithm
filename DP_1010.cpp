#pragma warning(disable : 4996)
#include<iostream>
#include<algorithm>
using namespace std;

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int bin(int n, int k) {
	int b[31][31];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) b[i][j] = 1;
			else b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	return b[n][k];
}

int main() {

	int t,n, m;
	int result=1;

	cin >> t;
	for (int i = 1; i<=t; i++) {
		cin >> n >> m;

		// result = m! / (n! * (m-n)!) = mCn
		result = bin(m, n);
		cout << result << endl;
	}

	return 0;
}
/*
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int t; //테스트 케이스 개수
	int n, m;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		double count = 1;
		for (int i = 1; i <= n; i++)
		{
			count = count * (m - i + 1) / i;
		}

		printf("%.0f\n", count);
	}
}
*/