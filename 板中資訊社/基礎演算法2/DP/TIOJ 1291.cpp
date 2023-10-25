#include "bits/stdc++.h"
using namespace std;

/*
動歸:N個箱子，包含了N+(N-1、N-2、...、2、1)個箱子等量珠子的排法
而第N個箱子排法:第M顆珠子有N-1個放法+第M顆珠子單獨一箱
*/
#define int long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, m;
const int yy=(int)1e6;
int arr[205][205];

signed main(){
	AC;

	memset(arr, 0, sizeof(arr));

	arr[0][0]=1;

    for(int i=1;i<=200;i++) {
        for(int j=1;j<=200;j++) {
            arr[i][j] = (arr[i][j-1] * i + arr[i-1][j-1]) % yy;
        }
    }

    while(cin >> n >> m && (n || m)) {
        int a=0;

        for(int i=1;i<=n;i++) a= (a+arr[i][m]) % yy;

        cout << a << "\n";
    }


	return 0;
}
