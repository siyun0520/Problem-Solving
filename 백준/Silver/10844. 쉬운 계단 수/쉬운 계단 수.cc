#include <iostream>

using namespace std;
int n;
long dp[101][11];
long mod = 1000000000;

int main() {
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % mod;
	}
	cout << sum;
}