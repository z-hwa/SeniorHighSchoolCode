#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

ll t, n, k;
vector<ll> v;

int main() {

    cin.sync_with_stdio(false), cin.tie(nullptr);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> k;
        for(ll i=0;i<n;i++) {
            ll num;
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());

        ll hight, low, mid;
        hight=v[n-1] - v[0], low=0;

        while(low < hight) {
            ll j=n-2, tot=0;
            mid = (hight + low)/2;
            for(ll i=n-1;i>=0;i--) {
                while(j>=0 && v[i] - v[j] <= mid) j--;
                tot+=j+1;
            }

            if(tot >= k) low=mid+1;
            else hight=mid;
        }

        cout << low << "\n";
    }


    return 0;
}
