#include "bits/stdc++.h"
using namespace std;

/*
DP:上、下移尋找
*/
#define int long long
#define N 202
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int m, n, ans=0;
int a, b, c, d;
int arr[N][N][N];

int f(int i, int x, int y) {
    return (a*i+b*x+c*y) % d;
}

signed main(){
	AC;

	memset(arr, 0, sizeof(arr));

    cin >> m >> n >> a >> b >> c >> d;

    for(int r=1;r<=m;r++) {
        for(int c=1;c<=m;c++) {
            for(int i=1;i<=min(r, n);i++) {
                arr[r][c][i] = max(arr[r-1][c-1][i-1] + f(i-1, r-1, c-1), max(arr[r-1][c][i], arr[r][c-1][i]));
                ans=max(arr[r][c][i], ans);
            }
        }
    }

    cout << ans << "\n";

	return 0;
}
