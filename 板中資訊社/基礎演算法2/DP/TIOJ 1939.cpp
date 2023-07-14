#include "bits/stdc++.h"
using namespace std;

/*
*/
#define int unsigned long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

const int MOD=1e9+9;
int arr[101], s[101];
int t, n;

signed main(){
	AC;

	arr[1]=1;
	s[1]=1;
	for(int i=2;i<=100;i++) {
        arr[i]=(arr[i-1]*3+1+s[i-2]*2) % MOD;
        s[i] =((arr[i]+s[i-1]) % MOD);
	}

	cin >> t;
	while(t--) {
        cin >> n;
        cout << arr[n] << "\n";
	}

	return 0;
}
