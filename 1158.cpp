#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int n, k;
int v[5001];

int main() {

	scanf("%d %d", &n, &k);

	int del = 0;
	int cnt = 0;
	bool flag = true;

	printf("<");
	while (flag) {
		for (int i = 1; i <= n; i++) {
			if (v[i] == 1) continue;
			if (del == n - 1) { flag = false; break; }
			else {
				cnt++;
				if (cnt == k) {
					v[i] = 1;
					printf("%d, ", i);
					del++;
					cnt = 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			printf("%d>", i);
		}
	}

	return 0;
}