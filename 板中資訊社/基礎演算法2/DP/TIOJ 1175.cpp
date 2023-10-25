#include "bits/stdc++.h"
using namespace std;

/*
DP:LIS
二分搜更新最長遞增字串
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, len=1;
ll val;
vector<ll> v;

int main(){

    AC
    cin >> n;

    v.push_back(0);
    for(int num=1, index;num<=n;num++) {
        cin >> val;
        index=lower_bound(v.begin(), v.end(), val)-v.begin();

        if(index==len) v.push_back(val), len++;
        else v[index]=val;
    }

    cout << len-1 << "\n";

	return 0;
}
