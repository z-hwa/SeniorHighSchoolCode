#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
typedef long long LL;

int main() {

    ios_base::sync_with_stdio(false);

    priority_queue<LL, vector<LL>, greater<LL>> qe;

    LL n, ans=0;
    while(cin >> n) {
        if(n==0) break;

        for(int i=0;i<n;i++) {
            LL num;
            cin >> num;
            qe.push(num);
        }

        while(qe.size()>1) {
            LL tem=0;
            tem+=qe.top();
            qe.pop();
            tem+=qe.top();
            qe.pop();
            ans+=tem;
            qe.push(tem);
        }

        cout << ans << "\n";
        ans=0;
        while(!qe.empty()) qe.pop();
    }

    return 0;
}
