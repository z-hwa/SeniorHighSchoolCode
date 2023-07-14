#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<pair<ll, int>>::iterator it_t;

#define MAX 100005
#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

int n, tem[MAX], ans;
int big = -1e9;

int main() {

    IOS;
    cin >> n;
    for(int i=0;i<n;i++) cin >> tem[i];

    for(int i=1;i<n;i++) {
        if(tem[i-1]>big) big = tem[i-1];
        ans = max(ans, big-tem[i]);
    }

    cout << ans << "\n";

    return 0;
}
