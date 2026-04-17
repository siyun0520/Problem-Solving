#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr(1000001);
vector <int> LIS(1000001);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n;
	int maxnum = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else {
		LIS.push_back(arr[0]);
		for (int i = 1; i < n; i++) {
			if (arr[i] > LIS.back()) {
				LIS.push_back(arr[i]);
				maxnum++;
			}
			else {
				auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
				*it = arr[i];
			}
		}
		cout <<  maxnum << endl;
	}
	return 0;
}