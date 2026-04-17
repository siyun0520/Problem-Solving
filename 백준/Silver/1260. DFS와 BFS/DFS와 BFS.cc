#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001][1001] = { 0 };
int visit[1001] = { 0 };
int n,m,s;

void clear(){
    for(int i=0;i<1001;i++){
        visit[i] = 0;
    }
}

void dfs(int now){
    cout << now << " ";

    visit[now]=1;

    for(int where=1;where<n+1;where++){
        if(arr[now][where]==1 && visit[where]==0){
            dfs(where);
        }
        if(where==n+1){
            return;
        }
    }
}


void bfs(int k){
    queue<int> map;

    map.push(k);
    
    while(!map.empty()){
        
        int now = map.front();
        map.pop();
    
        if(visit[now]==0){

            cout << now << " ";
            visit[now]=1;

        }
        for(int where=1;where<n+1;where++){
            if(arr[now][where]==1 && visit[where]==0){
                map.push(where);
            }
        }
    }

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> s;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    dfs(s);
    clear();
    cout << "\n";

    bfs(s);

    return 0;

}