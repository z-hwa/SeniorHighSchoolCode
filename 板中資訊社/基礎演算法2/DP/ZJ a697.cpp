#include "bits/stdc++.h"
using namespace std;

/*
動歸:對花的擺放種類以及目前擺放數量做DP
假設是第N種花放0~A[N]個
*/
#define int unsigned long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, m;
int arr[101][101], a[101];
const int MOD=1e6+7;

signed main(){
	AC;

	cin >> n >> m;

	memset(arr, 0, sizeof(arr));
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=a[1];i++) arr[1][i] = 1;
	for(int i=1;i<=n;i++) arr[i][0] = 1;

	for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            for(int k=0;k<=min(a[i], j);k++) arr[i][j]=(arr[i][j]+arr[i-1][j-k]) % MOD;
        }
	}

	cout << arr[n][m] << "\n";

	return 0;
}
