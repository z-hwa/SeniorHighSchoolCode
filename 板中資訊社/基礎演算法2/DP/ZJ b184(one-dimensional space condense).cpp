#include "bits/stdc++.h"
using namespace std;

/*
背包DP:
一維空間壓縮版本
需要反過來做DP，因為下一個是基於現在的，所以如果從前往後，會變動到
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;

int main(){

    AC

    while(cin >> n) {
        ll dp[105], ans=0, w, v;
        fill(dp, dp+105, 0);

        for(int i=1;i<=n;i++) {
            cin >> w >> v;
            for(int j=100;j>=w;j--) {
                dp[j]=max(dp[j-w]+v, dp[j]);
                ans=max(ans, dp[j]);
            }
        }
        cout << ans << "\n";
    }

	return 0;
}
