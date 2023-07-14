#include "bits/stdc++.h"
using namespace std;
/*
APCS
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

ll n;
ll arr[300005]={0}, puffix[300005]={0}, loc[300005], cop[300005] = {0};

int f(ll l, ll r) {
    if(l==r) return arr[l];

    for(ll i=l;i<=r;i++) cop[i]=arr[i];

    sort(cop+l, cop+l+(r-l+1));
    ll index = loc[cop[l]];

    ll left=0, right=0;

    if((l-1)>=0 && (index-1)>=0) left=puffix[index-1] - puffix[l-1];
    if(r<=n && index<=n) right=puffix[r] - puffix[index];

    if(right > left) return f(index+1, r);
    else if(left > right) return f(l, index-1);
    else if(right==left) return f(index+1, r);

    return 0;
}

int main(){
    AC

    cin >> n;
    for(ll i=1;i<=n;i++) {
        cin >> arr[i];
        loc[arr[i]]=i;
        puffix[i]=puffix[i-1]+arr[i];
    }

    cout << f(1, n) << "\n";

	return 0;
}
