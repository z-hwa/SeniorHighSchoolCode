#include "bits/stdc++.h"
using namespace std;

/*
�϶�DP:
���A:dp[i][j]:i~j�϶��̤p���V��
�ಾ��:���]len���סA�����I�A�����I�A�}�l�ಾ
��:i-j<=2�A�ƭȬO0
*/
#define int long long
#define N 55
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, lo;
int arr[N];
int tmp[N][N];

signed main(){
	AC;

	cin >> lo;
	cin >> n;
	arr[1]=0, arr[n+2]=lo;
	for(int i=2;i<=(n+1);i++) cin >> arr[i];

	for(int len=1;len<=(n+2);len++) {
        for(int l=1;l+len-1<=(n+2);l++) {
            int r=l+len-1;

            if(len==1) tmp[l][r]=0;
            else if(len==2) tmp[l][r]=0;
            else {
                tmp[l][r]=1e9;
                for(int k=l+1;k<r;k++) {
                    tmp[l][r]=min(tmp[l][r], tmp[l][k]+tmp[k][r]+arr[r]-arr[l]);
                }
            }
        }
	}

    cout << tmp[1][n+2] << "\n";

	return 0;
}
