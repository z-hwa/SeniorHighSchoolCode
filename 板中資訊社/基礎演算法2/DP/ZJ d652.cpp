#include "bits/stdc++.h"
using namespace std;

/*
°Ï¶¡DP:
*/
#define int long long
#define N 55
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
int arr[N];
int tmp[N][N];

signed main(){
	AC;

	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];

	for(int len=1;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            int r=l+len-1;

            if(len==1) tmp[l][r]=0;
            else if(len==2) tmp[l][r]=0;
            else {
                tmp[l][r]=1e9;
                for(int k=l+1;k<r;k++) {
                    tmp[l][r]=min(tmp[l][r], tmp[l][k]+tmp[k][r]+arr[l]*arr[r]*arr[k]);
                }
            }
        }
	}

    cout << tmp[1][n] << "\n";

	return 0;
}
