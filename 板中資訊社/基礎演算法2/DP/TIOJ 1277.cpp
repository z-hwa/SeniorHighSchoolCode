#include "bits/stdc++.h"
using namespace std;

/*
*/
#define int long long
#define N 505
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, ans=0;
int arr[N][N], tmp[N][N], b[N];

signed main(){
	AC;

	memset(arr, 0, sizeof(arr));
	memset(tmp, 0, sizeof(tmp));
	cin >> n;
	for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cin >> arr[i][j];
	}

	for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            tmp[i][j]=arr[i][j]+tmp[i-1][j];
        }
	}

	for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            int cursum=0;

            for(int k=1;k<=n;k++) {
                if(i==1) b[k]=tmp[j][k];
                else b[k]=tmp[j][k]-tmp[i-1][k];

                cursum=max(b[k], cursum+b[k]);
                ans=max(cursum, ans);
            }
        }
	}

	cout << ans << "\n";

	return 0;
}
