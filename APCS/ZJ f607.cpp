#include "bits/stdc++.h"
using namespace std;
/*
APCS
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

ll n, l;
ll arr[200005], ans=0;
vector<ll> v;

int main(){
    AC

    cin >> n >> l;
    for(int i=1, pos=0, index=0;i<=n;i++) {
        cin >> pos >> index;
        arr[index]=pos;
    }

    v.push_back(0);
    v.push_back(l);

    for(int i=1;i<=n;i++) {
        auto it=lower_bound(v.begin(), v.end(), arr[i]);
        int index=it-v.begin();

        ans=ans+(v[index] - v[index-1]);
        v.insert(it, arr[i]);
    }

    cout << ans << "\n";

	return 0;
}
