#include <iostream>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll tc,n;
ll dp[100001][4];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tc;
    dp[1][0]=0;
    dp[1][1]=1;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[3][0]=2;
    dp[3][1]=2;
    for (int i=4;i<=100000;i++) {
        dp[i][0]=(dp[i-3][1] +dp[i-2][1]+ dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-3][0] +dp[i-2][0]+ dp[i-1][0])%MOD;
    }
    while (tc--) {
        cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << endl;
    }
}