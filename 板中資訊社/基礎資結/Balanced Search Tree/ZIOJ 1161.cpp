#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

ll t, n, k;

int main() {
    AC
    cin >> t;
    while(t--) {
        int r = 1e9;
        cin >> n >> k;

        vector<pair<int, int>> v(n);
        priority_queue<int> pq;
        for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++) {
            pq.emplace(v[i].second);
            if(pq.size() == k) r=min(r, pq.top() + v[i].first), pq.pop();
        }

        cout << r << "\n";
    }


    return 0;
}
