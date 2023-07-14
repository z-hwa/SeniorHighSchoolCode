#include<bits/stdc++.h>
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
typedef long long ll;

struct node{
    ll v=0, sz=0, tag=0;
    ll rv() {
        return v+tag*sz;
    }
} ;

vector<node> vt;
ll n, q, v, x, y, k;
ll arr[500005];

void build(ll L, ll R, ll id) {
    vt[id].sz = R-L+1;
    if(L==R) {
        vt[id].v=arr[L];
        return;
    }

    ll M=(L+R)/2;
    build(L, M, 2*id+1);
    build(M+1, R, 2*id+2);

    vt[id].v = vt[2*id+1].v + vt[2*id+2].v;
}

void modify(ll L, ll R, ll l, ll r, ll v, ll id) {
    if(L==l && R==r) {
        vt[id].tag += v;
        return;
    }

    ll M=(L+R)/2;
    if(r<=M)
        modify(L, M, l, r, v, 2*id+1);
    else if(l>M)
        modify(M+1, R, l, r, v, 2*id+2);
    else {
        modify(L, M, l, M, v, 2*id+1);
        modify(M+1, R, M+1, r, v, 2*id+2);
    }

    vt[id].v = vt[2*id+1].rv() + vt[2*id+2].rv();
}

void push(ll id) {
    vt[2*id+1].tag+=vt[id].tag;
    vt[2*id+2].tag+=vt[id].tag;
    vt[id].v = vt[id].rv();
    vt[id].tag = 0;
    return;
}

ll query(ll L, ll R, ll l, ll r, ll id) {
    if(L==l && R==r)
        return vt[id].rv();

    push(id);
    ll M=(L+R)/2;

    if(r<=M)
        return query(L, M, l, r, 2*id+1);
    else if(l>M)
        return query(M+1, R, l, r, 2*id+2);
    else
        return query(L, M, l, M, 2*id+1) + query(M+1, R, M+1, r, 2*id+2);
}

int main(){
    cin >> n;
    node ori;
    vt.resize(4*n, ori);

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cin >> q;

    build(0, n-1, 0);

    while(q--) {
        cin >> v >> x >> y;
        x--, y--;
        if(v==1) {
            cin >> k;
            modify(0, n-1, x, y, k, 0);
        }
        else if(v==2) {
            cout << query(0, n-1, x, y, 0) << "\n";
        }
    }

    return 0;
}
