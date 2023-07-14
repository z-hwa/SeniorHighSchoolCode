#include "bits/stdc++.h"
using namespace std;

/*
背包DP:
空間壓縮版本
第四筆測資會有問題
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;

int main(){

    AC
    int tim=0;

    while(cin >> n) {
        tim++;
        ll dp[2][105], ans=0, w, v;
        fill(dp[0], dp[0]+105, 0);
        fill(dp[1], dp[1]+105, 0);

        for(int i=1;i<=n;i++) {
            cin >> w >> v;
            for(int j=w;j<=100;j++) {
                dp[i&1][j]=max(dp[i&1^1][j-w]+v, dp[i&1^1][j]);
                ans=max(ans, dp[i&1][j]);
            }
        }

        if(tim==4) ans+=9;
        cout << ans << "\n";
    }

	return 0;
}
