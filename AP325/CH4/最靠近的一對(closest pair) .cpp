#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Point{
    int x, y;
};

bool cmp(Point a, Point b) {
    return a.x < b.x;
}

int main() {

    int n;
    cin >> n;

    Point tem[n];

    for(int i=0;i<n;i++) {
        cin >> tem[i].x >> tem[i].y;
    }

    sort(tem, tem+n, cmp);

    multimap<int, int> mm;

    int ans = 1e9;

    for(int i=0;i<n;i++) {
        auto it=mm.lower_bound(tem[i].y - ans);
        while(it!=mm.end() && it->first <= tem[i].y + ans) {

            if(it->second < tem[i].x - ans){
                mm.erase(it);
                continue;
            }

            ans = min(ans, abs(tem[i].x - it->second) + abs(tem[i].y - it->first));

            it++;
        }
        mm.insert({tem[i].y, tem[i].x});
    }

    cout << ans << "\n";

    return 0;
}
