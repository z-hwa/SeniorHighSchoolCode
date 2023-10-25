#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

ll n, m;
ll ans=0;

int main(){
    AC

    cin >> n >> m;

    for(int i=1;i<min(n, m);i++) {
        ans=ans+(n-i)*(m-i)*i*i;
        if(i>=2) ans=ans+(n-i)*(m-i)*i;
    }

    cout << ans << "\n";

	return 0;
}
