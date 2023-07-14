#include "bits/stdc++.h"
using namespace std;

/*
���k:N�ӽc�l�A�]�t�FN+(N-1�BN-2�B...�B2�B1)�ӽc�l���q�]�l���ƪk
�Ӳ�N�ӽc�l�ƪk:��M���]�l��N-1�ө�k+��M���]�l��W�@�c
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
