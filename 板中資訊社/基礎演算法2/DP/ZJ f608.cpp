#include "bits/stdc++.h"
using namespace std;
/*
DP:LIS
APCSªr√D
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct Pos{
    ll x, y;
};

ll n;
Pos arr[200005];

bool cmp(Pos a, Pos b) {
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

int main(){
    AC

    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i].x >> arr[i].y;

    sort(arr, arr+n, cmp);

    vector<ll> v;

    for(int i=0;i<n;i++) {
        if(v.size()==0 || arr[i].y >= v.back()) {
            v.push_back(arr[i].y);
        }else {
            int index=(upper_bound(v.begin(), v.end(), arr[i].y) - v.begin());
            v[index]=arr[i].y;
        }
    }

    cout << v.size() << "\n";

	return 0;
}
