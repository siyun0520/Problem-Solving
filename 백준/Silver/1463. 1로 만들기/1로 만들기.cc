#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1'000'001];
int num;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> num;
	fill(dp, dp + 1'000'001, 2e9);
	dp[1] = 0;
	for (int i = 2; i <= num; i++) {
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[num] << "\n";

	return 0;
}