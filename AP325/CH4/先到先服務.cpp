#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {

    int n, m;
    LL ans = 0;
    freopen("Q_4_8_5.in","r",stdin);
    cin >> n >> m;

    LL peo[n];
    priority_queue<LL , vector<LL>, greater<LL>> tem;

    for(int i=0, j=0;i<n;i++, j++) {
        cin >> peo[i];

        if(j<m) {
            tem.push(peo[i]);
            ans = max(ans, peo[i]);
        }
        else {
            LL num = tem.top();
            num += peo[i];
            tem.pop();
            tem.push(num);
            ans = max(ans, num);
        }
    }

    cout << ans << "\n";

    return 0;
}
