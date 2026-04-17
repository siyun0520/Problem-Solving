#include <bits/stdc++.h>
using namespace std;
int a[1000],first[1000],second[1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        first[i]=1;
        for (int j=0;j<i;j++) {
            if (a[i]>a[j]) {
                first[i] = max(first[i],first[j]+1);
            }
        }
    }
    for (int i=n-1;i>=0;i--) {
        second[i]=1;
        for (int j=n-1;j>i;j--) {
            if (a[i]>a[j]) {
                second[i] = max(second[i],second[j]+1);
            }
        }
    }
    for (int i=0;i<n;i++) {
        int rst=first[i]+second[i];
        if (rst>ans) {
            ans=rst;
        }
    }
    cout << ans-1;
}