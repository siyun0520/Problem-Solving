#include <iostream>
#include <queue>

using namespace std;

static vector <int> parent;
int m, n;

int find(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
	}
}

typedef struct Edge {
	int a, b, c;
	bool operator > (const Edge& temp) const {
		return c > temp.c;
	}
}Edge;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(Edge{a,b,c});
	}
	int useedge = 0;
	int result = 0;

	while (useedge < n-1) {
		Edge now = pq.top();
		pq.pop();
		if (find(now.a) != find(now.b)) {
			Union(now.a, now.b);
			result = result + now.c;
			useedge++;
		}
	}
	cout << result;
}