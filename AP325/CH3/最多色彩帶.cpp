#include <bits/stdc++.h>;
using namespace std;

#define N 200010

int seq[N], cnt[N]={0};

int main() {

    int n, L, i;
    cin >> n >> L;

    int n_color=0;

    for(i=0;i<n;i++) {
        cin >> seq[i];
    }

    for(i=0;i<L;i++) {
        int color=seq[i];
        cnt[color]++;
        if(cnt[color]==1) n_color++;
    }

    int ans=n_color, left;

    for(left=0, i=L;i<n;i++, left++) {
        int color = seq[i];
        cnt[color]++;
        if(cnt[color]==1) n_color++;
        color=seq[left];
        cnt[color]--;
        if(cnt[color]==0) n_color--;
        ans = max(ans, n_color);
    }

    cout << ans << endl;

    return 0;
}
