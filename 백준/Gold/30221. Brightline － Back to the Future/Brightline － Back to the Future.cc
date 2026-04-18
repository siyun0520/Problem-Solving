#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값 (10억)

int n, m;
vector<pair<int, int>> adj[5001]; // adj[u] = { {v, cost}, ... }
int dist[5001];                  // dist[i]: 1번에서 i까지의 최소 시간 변화
bool in_queue[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;


    fill(dist, dist + n + 1, INF);


    for (int i = 0; i < m; ++i) {
        int s, e, a;
        char t; // 'b' or 'r'
        cin >> s >> e >> t >> a;

        if (t == 'b') {
            // 파란색: 나이가 듬 (비용 +a)
            adj[s].push_back({e, a});
        } else {
            // 빨간색: 젊어짐 (비용 -a)
            adj[s].push_back({e, -a});
        }
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);
    in_queue[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false; // 큐에서 꺼냈으므로 방문 가능 표시

        // 현재 노드 u와 연결된 모든 간선(u -> v) 탐색
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second; // 시간 변화 (a 또는 -a)


            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;

                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (dist[i] < INF && dist[i] < 0) {
            cout << i << "\n";
        }
    }

    return 0;
}
