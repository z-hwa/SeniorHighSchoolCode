#include <bits/stdc++.h>
using namespace std;

/*
graph basic dfs
*/

typedef long long ll;
const int N=805;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

vector<ll> v[N];
ll n=0, m=0;
ll tem[N];
string ans="No!!!\n";

void dfs(ll a, ll b) {
    tem[a]=1;
    if(a==b) {
        ans="Yes!!!\n";
        return;
    }

    for(auto i:v[a]) {
        if(tem[i]!=1) dfs(i, b);
    }
}

int main() {
    AC

    while(cin >> n >> m) {
        ans="No!!!\n";
        memset(tem, 0, sizeof(tem));
        for(int i=0;i<N;i++) v[i].clear();

        for(int i=0, a, b;i<m;i++) {
            cin >> a >> b;
            v[a].push_back(b);
        }

        ll a=0, b=0;
        cin >> a >> b;

        dfs(a, b);

        cout << ans;
    }


    return 0;
}
