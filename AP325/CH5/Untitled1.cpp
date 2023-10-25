#include<bits/stdc++.h>
using namespace std;

#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct p{
    int pmin, pmax;
};

p f(int a[], int s, int e) {
    if(s+1==e) return {a[s], a[s]};

    int m=(s+e)/2;

    p lc=f(a, s, m), ri=f(a, m, e);
    return {min(lc.pmin, ri.pmin), max(lc.pmax, ri.pmax)};
}

int main() {

    AC

    int a[11]={9, 10, 5, 4, 3, 20, 4, 5, 1, 5};
    p ans = f(a, 0, 10);

    cout << ans.pmin << " " << ans.pmax;

    return 0;
}
