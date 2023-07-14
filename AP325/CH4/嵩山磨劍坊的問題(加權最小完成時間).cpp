#include <bits/stdc++.h>
using namespace std;

struct Item{
    int t, w;
};

bool cmp(Item p, Item n) {
    return p.t * n.w < p.w * n.t;
}

int main() {

    int n;
    cin >> n;

    Item Q[n];

    for(int i=0;i<n;i++) {
        cin >> Q[i].t;
    }
    for(int i=0;i<n;i++) {
        cin >> Q[i].w;
    }

    sort(Q, Q+n, cmp);

    int time = 0, ans = 0;

    for(int i=0;i<n;i++) {
        time += Q[i].t;
         ans += time * Q[i].w;
    }

    cout << ans << "\n";

    return 0;
}
