#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

int n,m;
int arr[101][101];
int cnt = 0;


void dfs(int x,int y) {
	cnt++;
	arr[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + moveX[i];
		int ny = y + moveY[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (!arr[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
int main() {

	int k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if (!arr[i][j]) {
					arr[i][j] = 1;
				}
			}
		}
	}

	vector<int> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j]) {
				cnt = 0;
				dfs(i, j);
				result.push_back(cnt);
			}
			
		}
	}

	sort(result.begin(), result.end());

	printf("%d\n", result.size());
	for (int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);

	return 0;
}