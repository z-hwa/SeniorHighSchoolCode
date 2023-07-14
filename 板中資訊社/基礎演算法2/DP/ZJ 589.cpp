#include "bits/stdc++.h"
using namespace std;

/*
DP:
對三種情況做dp
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
int dp[41][3];

int main(){
    AC

    while(cin >> n && n) {
        for(int i=0;i<41;i++)
            for(int j=0;j<3;j++)
                dp[i][j]=0;

        int ans=0;

        for(int i=1, num;i<=n;i++) {
            cin >> num;
            for(int j=0;j<3;j++) {
                if(j==0) {
                    dp[i][j]=max(dp[i-1][1], dp[i][j]);
                }
                else if(j==1) {
                    dp[i][j]=max(dp[i-1][0]+num*2, max(dp[i][j], dp[i-1][2]+num*2));
                }
                else if(j==2) {
                    dp[i][j]=max(dp[i-1][0]+num, max(dp[i][j], dp[i-1][2]+num));
                }

                ans=max(ans, dp[i][j]);
            }
        }

        cout << ans << "\n";
    }

	return 0;
}
