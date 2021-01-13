#include<iostream>
#include<stack>
using namespace std;

int arr_stack[100000] = {0};
int idx = 0;
int result = 0;	//�߸� �踷����� ��

void arr_pop() {
	result += arr_stack[--idx];
	arr_stack[idx] = 0;
}
void arr_push() {
	arr_stack[idx++]++;
}
void arr_cut() {
	for (int i = 0; i < idx; i++) {
		arr_stack[i]++;
	}
}

int main() {

	string str;
	stack<char> s;	//�踷��⸦ ��� stack 

	cin >> str;
	for(int i = 0;i< str.length();i++){

		if (str[i] == '(') {	// �踷���?
			s.push(str[i]);
			if (str[i+1] == ')') {	//������
				if (!s.empty()) {
					s.pop();
					arr_cut();
					i++;
				}
			}
			else {	//�踷��� ����
				arr_push();
			}
		}
		else if (str[i] == ')') {	//�踷��� ��
			if (!s.empty()) {
				s.pop();
				arr_pop();
			}
		}
	}
	for (int i = 0; i < idx; i++) {
		result += arr_stack[i];
	}
	cout << result << '\n';

	return 0;
}