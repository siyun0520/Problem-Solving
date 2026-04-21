#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MIN;
int n, m;
int d[1001][1001];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] > INF && d[k][j] > INF) {
                    d[i][j] = max(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            d[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        d[s][t] = max(d[s][t], c);
    }
    floyd();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt = max(cnt, d[i][j]);
        }
    }
    cout << cnt << '\n';
    return 0;
}