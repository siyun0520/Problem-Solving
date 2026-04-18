#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct item {
    int impact;
    int time;
};
int dp[1001][10001];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<item>items(k+1);
    for (int i=1;i<=k;i++) {
        cin >> items[i].impact >> items[i].time;
    }

    for (int i=1;i<=k;i++) {
        for (int j=1;j<=n;j++) {
            if (items[i].time>j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-items[i].time]+items[i].impact);
            }
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}