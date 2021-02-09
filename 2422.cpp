#pragma warning(disable : 4996)
#include<iostream>

using namespace std;

int n, m;
int nop[201][201];
int cnt = 0;

int main() {
	//n 아이스크림 수 , m 안되는 조합 수
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		nop[a][b] = 1;
		nop[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!nop[i][j]) {
				for (int k = j + 1; k <= n; k++) {
					if (!nop[i][k] && !nop[j][k]) {
						cnt++;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}