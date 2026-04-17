#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, k;
typedef pair<int, int> edge;
vector<bool> visited;
vector<vector<edge>> mlist;
priority_queue<edge, vector<edge>, greater<>> pq;

int dijkstra(int start, int end) {
	const int max_position = 100000;
	vector<int> mdistance(max_position + 1, INT_MAX);
	pq.push(make_pair(0, start));
	mdistance[start] = 0;
	while (!pq.empty()) {
		int currenttime = pq.top().first;
		int currentpos = pq.top().second;
		pq.pop();
		if (currenttime > mdistance[currentpos]) {
			continue;
		}
		if (currentpos == end) {
			return currenttime;
		}
		vector<edge> next_positions = {
			{currenttime,currentpos * 2},
			{currenttime + 1, currentpos - 1},
			{currenttime + 1, currentpos + 1}
		};
		for (const auto& next : next_positions) {
			int next_time = next.first;  
			int next_pos = next.second; 

			
			if (next_pos >= 0 && next_pos <= max_position && next_time < mdistance[next_pos]) {
				mdistance[next_pos] = next_time;
				pq.push({ next_time, next_pos });
			}
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> k;

	if (n >= k) {
		cout << n - k << endl;
	}
	else {
		int result = dijkstra(n,k);
		cout << result << endl;
	}
	return 0;
}