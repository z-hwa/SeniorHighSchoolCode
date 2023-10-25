#include <bits/stdc++.h>
using namespace std;

struct Item{
    int w, f;
};

bool cmp(Item p, Item n) {
    return p.f * n.w > p.w * n.f;
}

int main() {

    int n;
    cin >> n;

    Item Q[n];

    for(int i=0;i<n;i++) {
        cin >> Q[i].w;
    }

    for(int i=0;i<n;i++) {
        cin >> Q[i].f;
    }

    sort(Q, Q+n, cmp);

    int ans = 0, ww = 0;

    for(int i=0;i<n;i++) {
        ans += ww * Q[i].f;
        ww += Q[i].w;
    }

    cout << ans << "\n";

    return 0;
}
