#include <bits/stdc++.h>
using namespace std;

/*
graph basic bipartite graph
*/

typedef long long ll;
const int N=40005;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int base[N]={0}, n=0, m=0, change[3]={0, 2, 1};


int main() {
    AC

    while(cin >> n >> m) {
        string ans="Yes\n";
        memset(base, 0, sizeof(base));
        if(n==m && n==0) break;
        for(int i=0, a=0, b=0;i<m;i++) {
            cin >> a >> b;
            if(base[a]==0 && base[b]==0) base[a]=1, base[b]=2;
            else if(base[a]==0) base[a]=change[base[b]];
            else if(base[b]==0) base[b]=change[base[a]];
            else if(base[a]==base[b]) {
                ans="No\n";
            }
            else if(base[a]!=base[b]) continue;
        }

        cout << ans;
    }

    return 0;
}
