#include <iostream>
#include <climits>
using namespace std;

int d[101][101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m;
    int cnt=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            d[i][j]=INT_MAX;
        }
    }
    for (int i=0;i<m;i++) {
        int win,lose;
        cin >> win >> lose;
        d[win][lose]=1;
    }

    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) {
                    int temp = d[i][k] + d[k][j];
                    if (temp < d[i][j]) {
                        d[i][j] = temp;
                    }
                }

            }
        }
    }
    for (int i=1;i<=n;i++) {
        int known=0;
        for (int j=1;j<=n;j++) {
            if (i==j) continue;
            if (d[i][j]<INT_MAX || d[j][i]<INT_MAX) {
                known++;
            }
        }
        if (known==n-1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}