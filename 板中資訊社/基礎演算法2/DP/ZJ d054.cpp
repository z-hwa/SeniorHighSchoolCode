#include "bits/stdc++.h"
using namespace std;

/*
*/

typedef long long ll;
#define int long long
#define N 20005
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int t, n, tem[45];

signed main(){
	AC;

	cin >> t;
	while(t--) {
        cin >> n;

        if(n==2) cout << "5\n", continue;
        else if(n==3) cout << "11\n", continue;

        tem[1]=1;
        tem[2]=4;
        tem[3]=2;
        for(int i=4;i<=n;i++) {
            tem[i]=tem[i-3]+tem[i-2]*4+tem[i-1]*2;
        }

        cout << tem[n] << "\n";
	}

	return 0;
}
