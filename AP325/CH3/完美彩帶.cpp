#include <bits/stdc++.h>
using namespace std;

#define N 40000

int seq[N], cnt[N];
int dic[N];

int c_id(int color, int nc) {
    if(color <= dic[0]) return 0;
    int p = 0;
    for(int jump=nc/2;jump>0;jump/=2) {
        while(jump+p<nc && dic[jump+p] < color) {
            p+=jump;
        }
    }

    return p+1;
}

int main() {

    int m, n, n_color, w_color, ans = 0, right = 0, left = 0;

    cin >> m >> n;

    for(int i=0;i<n;i++) {
        cin >> seq[i];
        dic[i] = seq[i];
    }

    sort(dic, dic+n);

    n_color = 1, w_color = 0;

    for(int i=1;i<n;i++) {
        if(dic[i]!=dic[i-1]) {
            dic[n_color] = dic[i];
            n_color++;
        }
    }

    for(int i=0;i<n;i++) {
        seq[i] = c_id(seq[i], n_color);
    }

    while(right < n) {
        cnt[seq[right]]++;
        if(cnt[seq[right]]==1) w_color++;

        right++;

        while(right - left > m) {
            cnt[seq[left]]--;

            if(cnt[seq[left]]==0) w_color--;

            left++;
        }

        if(w_color == n_color) {
            cout << w_color << "\n";
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
