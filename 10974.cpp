#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int visit[50];

void find(int k) {
	if (v.size() == k) {
		for (int i = 0; i < k; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= k; i++) {
			if (!visit[i]) {
				v.push_back(i);
				visit[i] = 1;
				find(k);
				v.pop_back();
				visit[i] = 0;
			}
		}
	}
}

int main() {

	int k;
	cin >> k;

	find(k);

	return 0;
}


/*
*		순열 구하는 함수   
* 
* next_permutation() - 오름차순
* prev_permutation() - 내림차순
* 
*/