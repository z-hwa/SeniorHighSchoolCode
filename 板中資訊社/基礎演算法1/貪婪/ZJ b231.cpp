#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, t=0, ans=0;
priority_queue<pair<int, int>> pq;

int main() {
    AC;

    cin >> n;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        pq.push(pair<int, int>(b, a));
    }

    for(;pq.size();pq.pop()) {
        t+=pq.top().second;
        ans=max(ans, t+pq.top().first);
    }

    cout << ans << "\n";

    return 0;
}

