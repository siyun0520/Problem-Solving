#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX 100

using namespace std;

vector <int> mdistance;
vector <bool> visited;
int V, e, start;
int u, v, w;
int cv;
typedef pair<int, int> edge;
vector <vector<edge>> mlist;
priority_queue <edge, vector<edge>, greater<edge>> pq;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);

    cin >> V >> e >> start;
    mdistance.resize(V + 1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);
    mlist.resize(V + 1);

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));
    }
    pq.push(make_pair(0, start));
    mdistance[start] = 0;

    while (!pq.empty()) {
        edge current = pq.top();
        pq.pop();
        cv = current.second;
        if (visited[cv]) {
            continue;
        }

        visited[cv] = true;
        for (int i = 0; i < mlist[cv].size(); i++) {
            edge temp = mlist[cv][i];
            int next = temp.first;
            int value = temp.second;

            if (mdistance[next] > mdistance[cv] + value) {
                mdistance[next] = value + mdistance[cv];
                pq.push(make_pair(mdistance[next], next));
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (visited[i]) {
            cout << mdistance[i] << endl;
        }
        else {
            cout << "INF" << endl;
        }
    }
}