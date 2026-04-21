#include <iostream>
#include <string.h>
using namespace std;
int dp[32769][182][4];
int facto(int n, int pos, int used) {
    if (n==0) return 1;
    if (used==4 || pos == 182) return 0;
    int &ret = dp[n][pos][used];
    if (ret != -1) return ret;
    ret = facto(n, pos+1, used);
    if (n>=pos*pos) ret+=facto(n-pos*pos, pos, used+1);
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;
        cout << facto(n, 1, 0) << endl;
    }
}