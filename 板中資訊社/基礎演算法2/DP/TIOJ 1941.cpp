#include "bits/stdc++.h"
using namespace std;

/*
LIS問題變形DP:
倒過來看
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
multiset<int> s;

int main(){
    AC

    cin >> n;

    for(int i=0, l, r;i<n;i++) {
        cin >> l >> r;
        auto index=s.upper_bound(r);
        s.insert(l);
        if(index!=s.end()) s.erase(index);
    }

    cout << s.size() << "\n";

	return 0;
}
