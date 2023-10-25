#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL tem[200000];
int n, d;

bool right(int l) {
    priority_queue<LL, vector<LL>, greater<LL>> qq;
    LL mmax = 0;

    for(int i=0;i<n;i++) {
        if(i<l) {
            qq.push(tem[i]);
            mmax = max(mmax, tem[i]);
        }
        else {
            LL num=qq.top()+tem[i];
            qq.pop();
            qq.push(num);
            mmax = max(mmax, num);
        }
    }

    if(mmax > d) return false;
    else return true;
}

int main() {

    ios::sync_with_stdio(false);

    freopen("Q_4_18_2.in", "r", stdin);
    cin >> n >> d;

    for(int i=0;i<n;i++) {
        cin >> tem[i];
    }

    int l = 0, jump = n;

    for(l=0, jump=n;jump>0;jump/=2) {
        while(l+jump<n && !right(l+jump)) {
            l+=jump;
        }
    }

    cout << l+1 << "\n";

    return 0;
}
