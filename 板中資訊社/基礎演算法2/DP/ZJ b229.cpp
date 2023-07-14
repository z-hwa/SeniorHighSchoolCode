#include "bits/stdc++.h"
using namespace std;

/*
動歸:路徑分直(A)橫(B)
下一個距離的直橫路徑:
直f(N, A)=f(N-1, A)+f(N, 2B)
橫f(N, B)=f(N, A)+f(N, B)
*/
#define int unsigned long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
int arr[51][2];

signed main(){
	AC;

	arr[1][0]=2, arr[1][1]=1;
	for(int i=2;i<=50;i++) {
        arr[i][0]=arr[i-1][0]+arr[i-1][1]*2;
        arr[i][1]=arr[i-1][1]+arr[i-1][0];
	}

	while(cin >> n) {
        cout << arr[n][0]+arr[n][1] << "\n";
	}

	return 0;
}
