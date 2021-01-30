#pragma warning(disable : 4996)
#include<iostream>

using namespace std;

int main() {
	int n, coinPrice, nextPrice;
	long long getMoney;

	cin >> n >> getMoney;
	cin >> coinPrice;
	for (int i = 0; i < n-1; i++) {
		cin >> nextPrice;
		if ((coinPrice < nextPrice) && getMoney > 0) {
			getMoney = (getMoney / coinPrice) * nextPrice + getMoney % coinPrice;
		}
		coinPrice = nextPrice;
	}
	cout << getMoney << endl;

	return 0;
}