#include <bits/stdc++.h>
using namespace std;

/*
DP bits
*/

typedef long long ll;
const int N=16;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int dp[N][1<<N], n=0, d[N];

int main() {
    AC

    cin >> n;

    for(int i=0;i<n;i++) cin >> d[i];

    memset(dp, 0x7f, sizeof(dp));
    dp[0][0]=0;

    for(int s=1;s<(1<<n);s++) {
        for(int a=0;a<n;a++) {
            if(s&(1<<a)) {
                for(int b=0;b<n;b++) {
                    int x=dp[b][s^(1<<a)]+abs(a-b);
                    x=((x-1)/d[a]+1)*d[a];
                    dp[a][s]=min(dp[a][s], x);
                }
            }
        }
    }

    int res=1e9;
    for(int i=0;i<n;i++) {
        res=min(dp[i][(1<<n)-1], res);
    }

    cout << res << "\n";

    return 0;
}
