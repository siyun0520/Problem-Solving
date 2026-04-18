#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int>psi;
int n,now;
unordered_map<int, psi> mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int a,b=0;
        cin >> a >> s >> b;
        mp[a]={s,b};
    }
    cin >> now;
    for (int i = 0; i < n; i++) {
        psi move = mp[now];
        string direction = move.first;
        int distance = move.second;
        if(direction == "R") {
            now+=distance;
        }
        else if(direction == "L") {
            now-=distance;
        }
    }
    cout << now << endl;
    return 0;
}