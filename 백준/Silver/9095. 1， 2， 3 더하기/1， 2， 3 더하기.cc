#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc,n;
int dp[100001][4];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tc;
    while (tc--) {
        cin >> n;
        dp[1][0] = 1;
        if (n > 1) {
            dp[2][0] = 1;
            dp[2][1] = 1;
        }
        if (n > 2) {
            dp[3][0] = 2;
            dp[3][1] = 1;
            dp[3][2] = 1;
        }
        for (int i = 4; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]);
            dp[i][1] = (dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2]);
            dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]+ dp[i - 3][2]);

        }
        int ans = (dp[n][0] + dp[n][1] + dp[n][2]);
        cout << ans << endl;;
    }
    return 0;
}