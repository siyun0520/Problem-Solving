#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	int a = str1.size();
	int b = str2.size();

	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= a; j++) {
			if (str1[j-1] == str2[i-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[b][a] << endl;
	return 0;
}