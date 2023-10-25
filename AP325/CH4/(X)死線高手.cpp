#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Work{
    LL t, d;
};

bool cmp(Work a, Work b) {
    return a.d-a.t < b.d-b.t;
}

int main() {

    ios::sync_with_stdio(false);

    freopen("Q_4_17_5.in", "r", stdin);
    int T, k;
    cin >> T;
    k=T;
    while(T--) {
        int n;
        cin >> n;

        Work tem[n];

        for(int i=0;i<n;i++)
            cin >> tem[i].t;
        for(int i=0;i<n;i++)
            cin >> tem[i].d;

        sort(tem, tem+n, cmp);

        LL time = 0, right = 1;

        for(int i=0;i<n;i++) {
            time += tem[i].t;
            if(tem[i].d < time) {
                right = 0;
                cout << "no\n";
                break;
            }
        }

        if(right==1) cout << "yes\n";

    }

    return 0;
}
