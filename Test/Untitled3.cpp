#include<bits/stdc++.h>
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
ll dm[200005], machi[200005];

bool cmp(int a, int b) {
    return a>b;
}

int main(){
    AC

    memset(dm, 0, sizeof(dm));
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        ll l, r, w;
        cin >> l >> r >> w;
        dm[l-1]+=w;
        dm[r]-=w;
    }

    for(int i=0;i<n;i++) {
        cin >> machi[i];
    }

    for(int i=1;i<n;i++) {
        dm[i]+=dm[i-1];
    }

    sort(dm, dm+n, cmp);
    sort(machi, machi+n);

    ll ans=0;
    for(int i=0;i<n;i++) {
        ans+=machi[i]*dm[i];
    }

    cout << ans << "\n";

    return 0;
}
