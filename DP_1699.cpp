#pragma warning(disable : 4996)
#include<iostream>
#include<math.h>
using namespace std;

int Dp[100001] = { 0 };
int main() {

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        Dp[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            Dp[i] = min(Dp[i], Dp[i - j * j] + 1);
        }
    }

    cout << Dp[n];
    return 0;
}