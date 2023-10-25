#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, k, tot=0, ans=0;
int arr[10005], tem[10005];

int main() {
    AC;

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1, arr+1+n);

    for(int i=1;i<=n;i++) tem[i]=tem[i-1]+arr[i];

    for(int i=1, l, r, mid;i<=n;i++) {
        l=0, r=i+1;
        while(l<r) {
            mid=(l+r)/2;

            if(mid*arr[i] - (tem[i] - tem[i-mid]) <= k) {
                l=mid+1;
                if(tot<mid) {
                    tot=mid;
                    ans=arr[i];
                }
            }
            else {
                r=mid;
            }
        }
    }

    cout << ans << " " << tot << "\n";

    return 0;
}
