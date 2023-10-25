#include "bits/stdc++.h"
using namespace std;

/*
分治:
二分搜+分治:壓時間
爬行法+前綴和
*/

typedef long long ll;
#define int long long
#define N 20005
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, k;
int base[N], pre[N], arr[N], id[N];

int mer(int l, int r, int q) {
    if(l>=r) return 0;

    int m=(l+r)/2, cnt=0;
    cnt+=mer(l, m, q);
    cnt+=mer(m+1, r, q);

    for(int i=l, j=m+1;i<=m;i++) {
        while(j<=r && (arr[j] - arr[i]) <= q) j++;
        cnt+=(r-j+1);
    }

    int i=l, j=m+1, idx=l;
    while(i<=m && j<=r) {
        if(arr[i] < arr[j]) id[idx++]=arr[i++];
        else id[idx++]=arr[j++];
    }

    while(i<=m) id[idx++]=arr[i++];
    while(j<=r) id[idx++]=arr[j++];

    memcpy(arr+l, id+l, sizeof(int) * (r-l+1));

    return cnt;
}

signed main(){
	AC;

    while(cin >> n >> k && (n || k)) {
        for(int i=0;i<n;i++) cin >> base[i];
        pre[0]=0;
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+base[i];

        int l=(-10000)*n - 1, r=(10000)*n;

        while((r-l) > 1) {
            int m=(l+r)/2, cnt;

            memcpy(arr, pre, sizeof(pre));
            cnt=mer(0, n, m);

            if(cnt > (k-1)) l=m;
            else r=m;
        }

        cout << r << "\n";
    }


	return 0;
}
