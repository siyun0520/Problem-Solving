#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> A;
vector<int> answer;
vector<bool> visited;

void bfs(int index) {
    queue<int> qu;
    qu.push(index);
    visited[index] = true;
    while (!qu.empty()) {
        int now_node = qu.front();
        qu.pop();
        for (int i : A[now_node]) {
            if (visited[i] == false) {
                visited[i] = true;
                answer[i]++;
                qu.push(i);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long n, m;
    cin >> n >> m;
    A.resize(n + 1);
    answer.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
    }
    visited.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        bfs(i);
    }
    int max_num = 0;
    for (int i = 1; i <= n; i++) {
        max_num = max(max_num, answer[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (answer[i] == max_num) {
            cout << i << " ";
        }
    }
}