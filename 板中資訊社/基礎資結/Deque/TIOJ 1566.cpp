#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 10000001
#define MAX 550000

ll n, m, k;
deque<pair<ll, ll>> mx, mi;
queue<pair<ll, ll>> ans;
ll l = 1;

int main() {

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        ll t;
        cin >> t;

        if(i > m) l++;

        while(mx.size() && i - mx.front().second >= m) mx.pop_front();
        while(mi.size() && i - mi.front().second >= m) mi.pop_front();
        while(mx.size() && t > mx.back().first) mx.pop_back();
        while(mi.size() && t < mi.back().first) mi.pop_back();
        mx.emplace_back(t, i), mi.emplace_back(t, i);
        if(mx.front().first - mi.front().first == k) ans.emplace(l, i);
    }
    for(int i=n-m+2;i<n;i++) {
        while(mx.size() && mx.front().second < i) mx.pop_back();
        while(mi.size() && mi.front().second < i) mi.pop_back();

        if(mx.front().first - mi.front().first == k) ans.emplace(i, n);
    }

    cout << ans.size();
    while(ans.size()) cout << "\n" << ans.front().first << " " << ans.front().second, ans.pop();

    return 0;
}
