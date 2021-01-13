#include<iostream>
#include<stack>
using namespace std;

int arr_stack[100000] = {0};
int idx = 0;
int result = 0;	//잘린 쇠막대기의 수

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
	stack<char> s;	//쇠막대기를 담는 stack 

	cin >> str;
	for(int i = 0;i< str.length();i++){

		if (str[i] == '(') {	// 쇠막대기?
			s.push(str[i]);
			if (str[i+1] == ')') {	//레이저
				if (!s.empty()) {
					s.pop();
					arr_cut();
					i++;
				}
			}
			else {	//쇠막대기 시작
				arr_push();
			}
		}
		else if (str[i] == ')') {	//쇠막대기 끝
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