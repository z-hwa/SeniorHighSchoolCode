#include "bits/stdc++.h"
using namespace std;

/*
DP:
對總和的一半做dp
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int main(){
    AC

    ll t;

    cin >> t;
    while(t--) {

        ll n;
        ll arr[1005], total=0;

        cin >> n;

        for(ll i=0;i<n;i++) {
            cin >> arr[i];
            total+=arr[i];
        }

        ll half=total/2;
        vector<ll> dp(half+1, 0);

        for(ll i=0;i<n;i++) {
            for(ll j=half;j>=arr[i];j--) {
                dp[j]=max(dp[j-arr[i]]+arr[i], dp[j]);
            }
        }

        cout << dp[half]*dp[half] + (total-dp[half])*(total-dp[half]) << "\n";
    }

	return 0;
}
