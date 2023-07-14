#include <bits/stdc++.h>
using namespace std;

#define N 1000000

struct XY{
    int x;
    int y;
};

XY xy[N];

bool cmp(XY a, XY b) {
    return a.x<b.x;
}

int main(){

    int n, l;

    cin >> n >> l;

    for(int i=0;i<n;i++) {
        cin >> xy[i].x;
    }

    for(int i=0;i<n;i++) {
        cin >> xy[i].y;
    }

    sort(xy, xy+n, cmp);

    int right=0, left=0, ans=0;

    while(right<n) {
        right++;

        while(abs(xy[right].x-xy[left].x)>l) {
            left++;
        }

        ans = max(ans, abs(xy[right].y-xy[left].y));
    }

    cout << ans << "\n";

    return 0;
}
