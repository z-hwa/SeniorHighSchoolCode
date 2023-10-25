#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<pair<ll, int>>::iterator it_t;

#define MAX 100005
#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

int t, tem[5005];

int main() {

    IOS;
    cin >> t;

    while(t--) {
        int n, ans=0;
        memset(tem, 0, sizeof(tem));
        cin >> n;
        for(int i=0;i<n;i++) cin >> tem[i];

        int vmax, vmin, vleft, vright;

        for(int i=0;i<n;i++) {
            vleft=tem[i];
            vmax=vmin=tem[i];
            for(int j=i;j<n;j++) {
                vright=tem[j];
                vmax=max(vmax, tem[j]);
                vmin=min(vmin, tem[j]);

                if(abs(vleft-vright)==abs(i-j) && vmax==max(tem[i], tem[j]) && vmin==min(tem[i], tem[j]) && i!=j) ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
