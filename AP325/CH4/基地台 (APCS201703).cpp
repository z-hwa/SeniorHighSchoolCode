#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n, k;

LL tem[55000];

bool cmp(LL a, LL b){
    return a < b;
}

bool enough(LL r){
    int base = k, len = -1;
    for(int i=0;i<n;i++) {
        if(tem[i]<=len) continue;
        if(base==0) return false;

        len=tem[i] + r;
        base--;
    }
    return true;
}

int main() {

        cin >> n >> k;

        for(int i=0;i<n;i++) {
            cin >> tem[i];
        }

        sort(tem, tem+n, cmp);

        LL len = 0, l = tem[n-1] - tem[0];
        for(LL jump = l/2;jump>0;jump/=2) {
            while(jump + len<l && !enough(jump + len)) {
                len += jump;
            }
        }

        cout << len+1 << "\n";

        for(int i=0;i<55000;i++) {
            tem[i] = 0;
        }


    return 0;
}
