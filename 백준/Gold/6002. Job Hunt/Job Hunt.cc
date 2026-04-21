#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = -1e18;
int d,p,c,f,s;
vector<pair<int, int>> adj[221]; 
ll profit[221];
bool in_queue[221];
int cycle_check[221];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= c; ++i) {
        profit[i] = INF;      
        in_queue[i] = false;
        cycle_check[i] = 0;
    }

    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, d});
    }

    for (int i = 0; i < f; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, d - t});
    }
    queue<int> q;

    // 시작 도시 S에서 D를 벌고 시작
    profit[s] = d;
    q.push(s);
    in_queue[s] = true;
    cycle_check[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false; // 큐에서 꺼냈으므로 false로 변경

        // 현재 노드 u와 연결된 모든 간선(u -> v) 탐색
        for (auto& edge : adj[u]) {
            int v = edge.first;      // 목적지 도시
            int weight = edge.second; // 순수 이익 (D - Cost)

            // 기존 v 도착 이익 vs (u를 거쳐 v로 오는 이익) 비교
            if (profit[v] < profit[u] + weight) {
                // (u를 거쳐 v로 오는) 새로운 경로가 더 이득일 경우 갱신
                profit[v] = profit[u] + weight;

                // v가 현재 큐에 없다면
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    cycle_check[v]++; // v가 큐에 들어간 횟수 증가

                    if (cycle_check[v] > c) {
                        cout << -1 << "\n";
                        return 0; // 즉시 종료
                    }
                }
            }
        }
    }

    ll max_profit = profit[1];
    for (int i = 2; i <= c; ++i) {
        max_profit = max(max_profit, profit[i]);
    }

    cout << max_profit << "\n";
    return 0;
}