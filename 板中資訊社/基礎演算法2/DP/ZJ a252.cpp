#include "bits/stdc++.h"
using namespace std;

/*
LCS問題變形DP:
三維!?
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

string s0, s1, s2, zero;
int dp[105][105][105], ans=0;

int main(){
    AC

    zero='0';
    cin >> s0 >> s1 >> s2;

    s0=zero+s0, s1=zero+s1, s2=zero+s2;

    for(int i=1;i<=s0.length();i++)
        for(int j=1;j<=s1.length();j++)
            for(int k=1;k<=s2.length();k++) {
                if(s0[i]==s1[j] && s1[j]==s2[k]) {
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    cout << s0[i] << "\n";
                }
                else dp[i][j][k]=max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                ans=max(ans, dp[i][j][k]);
            }


    cout << ans << "\n";

	return 0;
}
