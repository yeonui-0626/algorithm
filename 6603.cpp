#include<iostream>

using namespace std;

int arr[50];
int visit[50];
int cnt = 0;
int k;

int find(int next) {
	if (cnt == 6) {
		for (int i = 1; i <= k; i++) {
			if (visit[i])
				cout << arr[i] << " ";
		}
		cout << '\n';
		return 0;
	}

	for (int i = next; i <=k; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			cnt++;
			find(i + 1);
			visit[i] = 0;
			cnt--;
		}
	}
}

int main() {
	 
	cin >> k;

	while (k) {
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
		}

		find(1);
		
		cout << '\n';
		cin >> k;
	}
	return 0;
}