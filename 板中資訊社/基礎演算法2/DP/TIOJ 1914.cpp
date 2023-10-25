#include "bits/stdc++.h"
using namespace std;

/*
區間DP
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int t, n, m;
ll arr[105], dp[105][105];

int main(){

    cin >> t;
    while(t--) {
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j]=1e9;


        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> arr[i];

        for(int len=1;len<=n;len++) {
            for(int l=0;l+len-1<n;l++) {
                int r=l+len-1;

                if(len==1) dp[l][r]=1;
                else {
                    for(int k=l;k<r;k++) {
                        if(arr[l]==arr[r]) dp[l][r]=min(dp[l][r], dp[l][k]+dp[k+1][r]-1);
                        else dp[l][r]=min(dp[l][r], dp[l][k]+dp[k+1][r]);
                    }
                }
            }
        }

        cout << dp[0][n-1] << "\n";
    }

	return 0;
}
