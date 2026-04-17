#include <iostream>
#include <queue>
using namespace std;
int n,h,t;
int cnt;
int height[100001];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>h>>t;
    priority_queue<int> q;
    for(int i=0;i<n;i++) {
        cin>>height[i];
        q.push(height[i]);
    }
    while (cnt < t && q.top()>=h) {
        int temp = q.top();
        q.pop();
        if (temp==1) {
            q.push(temp);
        }
        cnt++;
        temp = temp/2;
        q.push(temp);
    }
    if (q.top() < h) {
        cout << "YES" << endl;
        cout << cnt << endl;
    }
    else{
        cout << "NO" << endl;
        cout << q.top() << endl;
    }
}