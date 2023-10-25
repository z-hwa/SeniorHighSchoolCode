#include "bits/stdc++.h"
using namespace std;

/*
DP:
需遍歷所有摺紙可能性
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, m;
int dp[101][101];

int main(){
    AC

    for(int i=1;i<=100;i++) {
        for(int j=1;j<=100;j++) {
            dp[i][j]=1e9;
            if(i!=j) {
                for(int x=1;x<i;x++) dp[i][j]=min(dp[x][j]+dp[i-x][j], dp[i][j]);
                for(int y=1;y<j;y++) dp[i][j]=min(dp[i][y]+dp[i][j-y], dp[i][j]);
            }
            else if(i==j) dp[i][j]=1;
        }
    }

    while(cin >> n >> m) {
        cout << dp[n][m] << "\n";
    }

	return 0;
}
