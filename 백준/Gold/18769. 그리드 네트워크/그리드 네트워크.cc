#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct network {
	int start;
	int end;
	int price;
};
vector <network> lines;
int t, r, c;
int parent[500 * 500 + 1];
bool compare(network a, network b) {
	return a.price < b.price;
}
void init() {
	for (int i = 0; i < r * c; i++) {
		parent[i] = i;
	}
	lines.clear();
	lines.reserve(r*c);
}

void getrelation() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c - 1; j++) {
			int start = c * i + j;
			int end = c * i + j + 1;
			int price;
			cin >> price;
			lines.push_back({ start,end,price });
		}
	}
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			int start = c * i + j;
			int end = c * (i + 1) + j;
			int price;
			cin >> price;
			lines.push_back({ start,end,price });
		}
	}
}
int find(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		int result = 0;
		cin >> r >> c;
		init();
		getrelation();
		sort(lines.begin(), lines.end(), compare);
		for (int i = 0; i < lines.size(); i++) {
			int a = lines[i].start;
			int b = lines[i].end;
			if (find(a) == find(b)) continue;
			Union(a, b);
			result += lines[i].price;
		}
		cout << result << endl;
	}
	return 0;
}