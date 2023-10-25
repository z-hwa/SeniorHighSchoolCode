#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n;

struct Gan{
    LL m, s, t;
};

bool cmp(Gan a, Gan b) {
    return a.s < b.s;
}

int main() {

    ios::sync_with_stdio(false);

    freopen("Q_4_19_1.in", "r", stdin);

    cin >> n;
    Gan tem[n];

    cout << "ll\n";

    for(int i=0;i<n;i++) {
        cin >> tem[i].m >> tem[i].s >> tem[i].t;
    }

    sort(tem, tem+n, cmp);

    LL ans = 0, num = 0;
    Gan mm;
    mm.t = 1e9;
    stack<Gan> tar;

    tar.push(mm);
    tar.push(tem[0]);
    ans = tem[0].m, num = tem[0].m;

    cout << "jj\n";

    for(int i=1;i<n;i++) {

        while(tar.top().t < tem[i].s) {
            num-=tar.top().m;
            tar.pop();
        }

        tar.push(tem[i]);
        num+=tar.top().m;
        ans = max(ans, num);
        cout << "fds\n";
    }

    cout << ans << "\n";

    return 0;
}
