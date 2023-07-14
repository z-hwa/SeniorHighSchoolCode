#include <bits/stdc++.h>
using namespace std;

struct ACT{
    int st;
    int ed;
};

ACT act[100000];

bool cmp(ACT a, ACT b) {
    return a.ed < b.ed;
}

int main() {

    int n;

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> act[i].st >> act[i].ed;
    }

    sort(act, act+n, cmp);

    int ans=0, endtime=-1;

    for(int i=0;i<n;i++) {
        if(act[i].st > endtime) {
            ans++;
            endtime = act[i].ed;
        }
    }

    cout << ans << "\n";

    return 0;
}
