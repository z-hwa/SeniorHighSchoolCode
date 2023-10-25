#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAX 500005
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct node{
    int v, ans;
};

vector<node> v;
int a[MAX];
int n;

void build(int L, int R, int id) {
    if(L==R) {
        v[id].v=a[L];
        return;
    }

    int M=(L+R)/2;
    build(L, M, 2*id+1);
    build(M+1, R, 2*id+2);
    v[id].v=max(v[2*id+1].v, v[2*id+2].v);
}

int query(int L, int R, int l, int r, int id) {
    if(l==L && r==R)
        return v[id].v;
    int M=(L+R)/2;

    if(r<=M)
        return query(L, M, l, r, 2*id+1);
    else if(l>M)
        return query(M+1, R, l, r, 2*id+2);
    else {
        return max(query(L, M, l, M, 2*id+1), query(M+1, R, M+1, r, 2*id+2));
    }
}

int main() {

    AC
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    node u;
    u.v=0;
    v.resize(4*n, u);
    build(0, n-1, 0);
    int times=0, a=0, b=0;
    int l=0, r=0;
    cin >> times;
    while(times--) {
        cin >> a >> b;
        l=min(a, b)-1;
        r=max(a, b)-1;
        cout << query(0, n-1, l, r, 0) << "\n";
    }

    return 0;
}
