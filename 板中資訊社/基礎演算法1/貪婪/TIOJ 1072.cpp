#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;

int main() {
    AC;

    while(cin >> n) {
        if(n==0) break;

        ll c, e, r=0, t=0;
        priority_queue<pair<ll, ll>> pq;

        for(int i=0;i<n;i++) {
            cin >> c >> e;
            pq.push(make_pair(e, c));
        }

        for(;pq.size();pq.pop()) {
            r+=pq.top().second;
            t=max(t, r+pq.top().first);
        }
        cout << t << "\n";
    }

    return 0;
}

