#include <iostream>
#include <vector>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    vector<int>dp(101,0);
    dp[1]=2, dp[2]=4;
    int num=3;
    for (int i=3;i<=n;i++) {
        dp[i]=dp[i-1]+num;
        if (i%3!=0) {
            num++;
        }
    }
    cout << dp[n] << endl;
    return 0;
}