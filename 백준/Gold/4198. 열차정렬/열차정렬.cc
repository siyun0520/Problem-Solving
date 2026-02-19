#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr(2001);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n==0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> lis(n,1);
    vector<int> lds(n,1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
            if (arr[j] < arr[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int max_n = 0;
    for (int i = 0; i < n; i++) {
        max_n = max(max_n, lis[i] + lds[i] - 1);
    }
    cout << max_n << endl;
    
    return 0;
}