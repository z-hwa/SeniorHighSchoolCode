#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

int n;
float tem[SIZE];
float ans;

int main() {
    AC

    while(cin >> n) {
        memset(tem, sizeof(tem), 0);
        ans = 0;

        float mx = 1e-9, mn = 1e9;
        for(int i=0;i<n;i++) cin >> tem[i], ans+=tem[i], mx = max(mx, tem[i]), mn = min(mn, tem[i]);

        ans=ans-(mn+mx);

        cout << fixed << setprecision(2) << ans/(n-2)+1e-9 << "\n";

    }

    return 0;
}
