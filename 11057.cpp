

/*
 ���� 11057 ��������

 �ð��ʰ�

*/

#include<iostream>
#include<vector>

using namespace std;

int n;
int cnt=0;
int result;

void dfs(vector<int>& v,int prev) {
	if (v.size() == n) {
		cnt++;
		/*
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << '\n';
		*/
		return;
	}
	else {
		for (int i = prev; i <= 9; i++) {
			v.push_back(i);
			dfs(v, i);
			v.pop_back();
		}
	}
}

int main() {
	cin >> n;
	vector<int> v;
	dfs(v, 0);
	
	result = cnt % 10007;

	cout << result;

	return 0;
}