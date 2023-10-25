#include "bits/stdc++.h"
using namespace std;

/*
動態規劃:[i][j]，以i為等差數列的末尾，j為等差數列的公差，做狀態轉移。
轉移時需要額外加一，因為單個數字也是
*/

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

const int rf=20000, m=1e9+7;
int n, ans=0;
int arr[1005], tem[1005][40005];

int main() {
    AC;

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    ans=n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            tem[i][arr[i]-arr[j]+rf]=((tem[i][arr[i]-arr[j]+rf]) + (tem[j][arr[i]-arr[j]+rf]) + 1) % m;
            ans = (ans + tem[j][arr[i]-arr[j]+rf] + 1) % m;
        }
    }

    cout << ans << "\n";

    return 0;
}
