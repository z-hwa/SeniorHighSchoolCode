#include<bits/stdc++.h>
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
typedef long long ll;

const ll M=1000005, N=100005;

struct Node{
    int x1, x2, y, val;
}arr[2*N];

struct node{
    int val, tag;
}seg[4*M];

ll n;

void modify(ll L, ll R, ll l, ll r, ll v, ll id) {
    if(R <= L || l >= R || r<=L) return;
    if(l<=L && r>=R) {
        seg[id].tag+=v;
        return;
    }

    ll M=(R+L)/2;
    modify(L, M, l, r, v, 2*id);
    modify(M, R, l, r, v, 2*id+1);

    seg[id].val=(seg[2*id].tag?M-L:seg[2*id].val)
                +(seg[2*id+1].tag?R-M:seg[2*id+1].val);
}

bool cmp(Node a, Node b) {
    return a.y < b.y;
}

int main(){
    AC

    memset(seg, 0, sizeof(seg));
    memset(ori, 0, sizeof(ori));

    ll l, r, d, u;
    cin >> n;

    for(int i=0;i<(n<<1);i+=2) {
        cin >> l >> r >> d >> u;
        ori[i] = (Node){l, r, d, 1};
        ori[i+1] = (Node){l, r, u, -1};
    }
    stable_sort(ori, ori+(n<<1), cmp);

    ll y0=0, val=0;
    ll ans=0;

    for(int i=0;i<(n<<1);i++) {
        ans+=(ori[i].y-y0)*val;
        modify(1, 0, M, ori[i].x1, ori[i].x2, ori[i].val);

        y0=ori[i].y;
        val=seg[1].val;
    }

    cout << ans << "\n";

    return 0;
}
