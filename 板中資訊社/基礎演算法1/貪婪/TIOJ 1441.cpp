#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int main() {
    AC;

    int n, num, h=-1, che=1, ans=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> num;
        if(num==h) continue;
        if(num < h ^ che) {
            che=!che, ans++;
        }
        h=num;
    }

    if(che) ans--;
    cout << ans << "\n";

    return 0;
}

