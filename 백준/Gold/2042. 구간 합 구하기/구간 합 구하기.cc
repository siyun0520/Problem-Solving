#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MAX = 1'000'000;
vector <ll> seg;
ll arr[MAX+1];

ll init(int idx,int st, int en) {
    if (st==en) {
        return seg[idx]=arr[st];
    }
    int mid = (st+en)/2;
    return seg[idx] = init(idx*2, st, mid) + init(idx*2+1, mid+1, en);
}
ll update (int idx, int st, int en, int i, ll val) {
    if (i<st||en<i) return seg[idx];
    if (st==en) return seg[idx] = val;
    int mid = (st+en)/2;
    return seg[idx] = update(idx*2,st,mid,i,val)+update(idx*2+1,mid+1,en,i,val);
}
ll query (int idx, int st, int en, int l, int r) {
    if (r<st || en < l) return 0;
    if (l<=st && en<=r) return seg[idx];
    int mid = (st+en)/2;
    return query(idx*2,st,mid,l,r)+query(idx*2+1,mid+1,en,l,r);
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    seg.resize(4*n);
    init(1,1,n);
    for (int i=0;i<m+k;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        if (a==1) {
            update(1,1,n,b,c);
        }
        else if (a==2) {
            cout << query(1,1,n,b,c) << '\n';
        }
    }

}
