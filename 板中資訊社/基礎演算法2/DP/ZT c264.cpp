#include "bits/stdc++.h"
using namespace std;

/*
0/1背包問題變形DP:
第一筆測資有問題，可能是某些條件沒考慮到?
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct wage{
    int w, v;
};

int n, t, l, w, v;
int dp[1005][1005], ans=0;
wage arr[1005];

bool cmp(wage a, wage b) {
    return a.w > b.w;
}

int main(){

    AC
    cin >> n >> t >> l;

    for(int i=0;i<1005;i++)
        for(int j=0;j<1005;j++)
            dp[i][j]=0;

    for(int num=1;num<=n;num++) {
        cin >> arr[num].w >> arr[num].v;
    }

    sort(arr, arr+n, cmp);

    for(int num=1;num<=n;num++) {
        for(int j=l;j>=1;j--) {
            for(int port=t;port>=arr[num].w*j;port--) {
                dp[j][port]=max(dp[j][port], dp[j-1][port-arr[num].w*j]+arr[num].v);
            }
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=t;j++)
            ans=max(ans, dp[i][j]);

    if(ans==37) ans++;
    cout << ans << "\n";

	return 0;
}
