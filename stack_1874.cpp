#include<iostream>
#include<stack>
#include<queue>

using namespace std;
/*
cin/cout�� ����ϴ� ���
cin.tie(NULL); �� io_base::/sync_with_stdio(false);�� �߰��ϰ�
endl ��� ���๮��('\n')�� ���� ����� �ӵ��� ���� �� �ִ�.
��, scanf, printf, puts,getchar���� C�� ����� ����� ����ϸ� �ȵȴ�.

c++�� �˰��� ������ Ǯ �� �ð��� �����ϱ� ���� printf, scanf �� ����ϴ� ��찡 �ִ�.
���� ����� ���� cout �� cin�� �� ��ŭ ������ ����� �ش�.

[iso::sync_with_stdio(false);]
iso::sync_with_stdiosms cpp�� iostream�� c�� stdio�� ����ȭ �����ִ� ������ �Ѵ�.
�̴� iostream, stdio�� ���۸� ��� ����ϱ� ������ �����̰� �߻��ϰ� �ȴ�.
iso::sync_with_stdio(false)�� �ϰԵǸ� c++���� �������� ���۸� �����ϰ� �ǰ�
c�� ���� ����� �����Ͽ� ����� �� ���� �ȴ�.
��� ������ ���� �پ������Ƿ� �ӵ��� ��������.

[cin.tie(NULL);]
����Ʈ�� cout, cin�� tie �Ǿ� �ִ�.
���� cout << "hi"; cin >> name; �� ������� ����Ʈ�� ��� hi�� ���� ��µǰ� name�� �Է��� ���̴�.
�׷��� untie�� �ܷ� cout���κ��� cin�� untie �غα� ������ ���� �Էº��� �ް� �ȴ�.
�׷��� hi�� ������ �ʴµ�, cout ����Ʈ������ ��� ���� �����ų� ���۰� ����ã������ flushed�ǰ� ��µǱ� �����̴�.
���� cin�� cout���� untie�ϰ� �ʹٸ� cin���� �Է��ϱ� ���� cout���� ����� �Ҷ� ���� ���������� flush�� ����� �Ѵ�.

cin.tie(NULL)�� cin�� cout�� ������ Ǯ���ش�. �⺻������ cin���� ���� �� ���� ��� ���۸� ���µ�, ���������� ���ڸ� ����������
ȭ�鿡 �ٷ� �������� ���� �߿����� �ʴ�. �Է°� ����� ������ �ݺ��ؾ� �ϴ� ��� �ʼ����̴�.

[endl]
endl - ���� + ���� ���۸� ����ִ� ������ ��(flush) -> ����
\n - only ����
*/
int main() {
	cin.tie(NULL);	//�� ���� �� Ʋ�ȴٰ� ����.
	ios_base::sync_with_stdio(false);

	int n;
	stack<int> s;
	queue<char> q;

	cin >> n;
	int num = 1;	//stack�� ���� ���� 1 ~ 
	s.push(0);

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		if (data > s.top()) {	//data�� top ���� ũ��.
			int j;
			for (j = num; j <= data; j++) {	// ~ data ���� push
				s.push(j);
				q.push('+');
			}
			num = j;		//stack�� data���� ���� ���� push ������ ���� +1 �ؼ� ����
			//���� data pop & -
			s.pop();
			q.push('-');
		}
		else if (data == s.top()) {	//top�� �ִ� ���ڿ� data�� ������ pop 
			s.pop();
			q.push('-');
		}
		else { //data�� top���� ���� ���
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