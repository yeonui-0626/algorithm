#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool Check(string str) {
	int len = (int)str.length();
	stack<char> s;

	for (int i = 0; i < len; i++) {
		char c = str[i];

		if (c == '(') {
			s.push(str[i]);
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return s.empty();
}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {

		string str;
		cin >> str;

		if (Check(str)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;

}