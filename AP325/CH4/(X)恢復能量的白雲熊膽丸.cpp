#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, k, ene = 0;

LL tem[550000];

bool enough(LL r){
    LL base = k-1, len = r;
    for(int i=0;i<n;i++) {
        if(tem[i]<=len) {
            len-=tem[i];
            continue;
        }
        if(base==0) return false;

        len=r - tem[i];
        base--;
    }
    return true;
}

int main() {

        freopen("Q_4_10_4.in", "r", stdin);
        cin >> n >> k;

        for(int i=0;i<n;i++) {
            cin >> tem[i];

            ene+=tem[i];
        }

        LL len = 0, l = ene-1;
        for(LL jump = l/2;jump>0;jump/=2) {
            while(jump + len<l && !enough(jump + len)) {
                len += jump;
            }
        }

        cout << len+1 << "\n";

    return 0;
}
