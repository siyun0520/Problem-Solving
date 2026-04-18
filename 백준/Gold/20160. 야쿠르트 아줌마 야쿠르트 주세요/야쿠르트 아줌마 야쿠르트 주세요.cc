#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const long long INF = 1e18;

int V, E, u, v, w, start;
typedef pair<long long, int> edge;
vector<vector<edge>> graph;
int yogurt[10];
long long Map[10001][10001]; // 정점 간 최단 거리

// 다익스트라로 시작점에서 모든 정점까지 거리 갱신
void dijkstra(int start) {
    vector<long long> dist(V + 1, INF);
    priority_queue<edge, vector<edge>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        if (dist[now] < cost) continue;
        for (auto& [next, weight] : graph[now]) {
            if (dist[next] > dist[now] + weight) {
                dist[next] = dist[now] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        Map[start][i] = dist[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> V >> E;
    graph.resize(V + 1);

    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < 10; ++i) {
        cin >> yogurt[i];
    }
    cin >> start;

    // 거리 테이블 초기화
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            Map[i][j] = (i == j ? 0 : INF);
        }
    }

    // 아줌마 동선과 내 위치에서 다익스트라 실행
    for (int i = 0; i < 10; ++i) dijkstra(yogurt[i]);
    dijkstra(start);

    long long Time = 0;
    long long answer = INF;

    if (yogurt[0] == start) answer = yogurt[0];

    int i = 0, j = 1;
    while (j < 10) {
        if (Map[yogurt[i]][yogurt[j]] == INF) {
            ++j;
            continue;
        }
        Time += Map[yogurt[i]][yogurt[j]];
        if (Time >= Map[start][yogurt[j]]) {
            answer = min(answer, (long long)yogurt[j]);
        }
        i = j;
        ++j;
    }

    if (answer == INF) cout << -1 << '\n';
    else cout << answer << '\n';
}
