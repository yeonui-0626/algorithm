#include<iostream>
#include<stack>
#include<queue>

using namespace std;
/*
cin/cout을 사용하는 경우
cin.tie(NULL); 과 io_base::/sync_with_stdio(false);를 추가하고
endl 대신 개행문자('\n')를 쓰면 입출력 속도를 줄일 수 있다.
단, scanf, printf, puts,getchar등의 C의 입출력 방식을 사용하면 안된다.

c++로 알고리즘 문제를 풀 때 시간을 절약하기 위해 printf, scanf 를 사용하는 경우가 있다.
위의 방법을 쓰면 cout 과 cin을 그 만큼 빠르게 만들어 준다.

[iso::sync_with_stdio(false);]
iso::sync_with_stdiosms cpp의 iostream을 c의 stdio와 동기화 시켜주는 역할을 한다.
이는 iostream, stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하게 된다.
iso::sync_with_stdio(false)를 하게되면 c++만의 독립적인 버퍼를 생성하게 되고
c의 버퍼 들과는 병행하여 사용할 수 없게 된다.
대신 버퍼의 수가 줄어들었으므로 속도는 높아진다.

[cin.tie(NULL);]
디폴트는 cout, cin이 tie 되어 있다.
만약 cout << "hi"; cin >> name; 이 순서라면 디폴트의 경우 hi가 먼저 출력되고 name을 입력할 것이다.
그러나 untie의 겨루 cout으로부터 cin을 untie 해부기 때문에 먼저 입력부터 받게 된다.
그러나 hi는 보이지 않는데, cout 디폴트에서는 출력 명열을 내리거나 버퍼가 가득찾을때만 flushed되고 출력되기 떄문이다.
따라서 cin을 cout에서 untie하고 싶다면 cin으로 입력하기 전에 cout으로 출력을 할때 마다 지속적으로 flush를 해줘야 한다.

cin.tie(NULL)은 cin과 cout의 묶음을 풀러준다. 기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 온자린 저지에서는
화면에 바로 보여지는 것이 중요하지 않다. 입력과 출력을 여러번 반복해야 하는 경우 필수적이다.

[endl]
endl - 개행 + 내부 버퍼를 비워주는 역할을 함(flush) -> 느림
\n - only 개행
*/
int main() {
	cin.tie(NULL);	//안 썼을 때 틀렸다고 나옴.
	ios_base::sync_with_stdio(false);

	int n;
	stack<int> s;
	queue<char> q;

	cin >> n;
	int num = 1;	//stack에 넣을 숫자 1 ~ 
	s.push(0);

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		if (data > s.top()) {	//data가 top 보다 크면.
			int j;
			for (j = num; j <= data; j++) {	// ~ data 까지 push
				s.push(j);
				q.push('+');
			}
			num = j;		//stack에 data까지 넣은 다음 push 연산을 위해 +1 해서 저장
			//현재 data pop & -
			s.pop();
			q.push('-');
		}
		else if (data == s.top()) {	//top에 있는 숫자와 data가 같으면 pop 
			s.pop();
			q.push('-');
		}
		else { //data가 top보다 작은 경우
			cout << "NO" << '\n';
			return 0;
		}
	}

	while (!q.empty()) {
		cout << q.front() << '\n';
		q.pop();
	}

	return 0;
}