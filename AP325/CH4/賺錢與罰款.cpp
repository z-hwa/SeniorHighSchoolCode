#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Work{
    LL t, r;
};

bool cmp(Work a, Work b) {
    return a.t < b.t;
}

int main() {

    int n;
    cin >> n;
    Work tem[n];

    for(int i=0;i<n;i++) {
        cin >> tem[i].t;
    }

    for(int i=0;i<n;i++) {
        cin >> tem[i].r;
    }

    LL ans = 0;

    for(int i=0;i<n;i++) {
        ans+=tem[i].r - tem[i].t;
    }

    sort(tem, tem+n, cmp);

    for(int i=0;i<n;i++) {
        ans-=tem[i].t*(n-i-1);
    }

    cout << ans << "\n";

    return 0;
}
