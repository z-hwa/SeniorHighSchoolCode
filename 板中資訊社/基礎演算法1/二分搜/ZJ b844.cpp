#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

vector<ll> v;
ll n, q;

int main() {

    while(cin >> n >> q) {
    v.clear();
    ll num;
    for(ll i=0;i<n;i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(ll i=0;i<q;i++) {
        cin >> num;
        num=upper_bound(v.begin(), v.end(), num) - v.begin();
        if(num%2==1) cout << "1\n";
        else cout << "0\n";
    }

    }

    return 0;
}
