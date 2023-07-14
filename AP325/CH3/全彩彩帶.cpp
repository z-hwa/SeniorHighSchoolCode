#include <bits/stdc++.h>
using namespace std;

#define N 40000

int seq[N], cnt[N];
int dic[N];

int c_id(int color, int nc) {
    if(color <= dic[0]) return 0;
    int p=0;
    for(int jump=nc/2;jump>0;jump/=2) {
        while((jump+p) < nc && dic[jump+p] < color) {
            p+=jump;
        }
    }

    return p+1;
}

int main() {

    int n, n_color;

    cin >> n;

    int left = 0, right = 0, w_color = 0, shortest = n;

    for(int i=0;i<n;i++) {
        cin >> seq[i];
        dic[i] = seq[i];
    }


    sort(dic, dic+n);
    n_color=1;

    for(int i=1;i<n;i++) {
        if(dic[i] != dic[i-1]) {
            dic[n_color] = dic[i];
            n_color++;
        }
    }


    for(int i=0;i<n;i++) {
        seq[i] = c_id(seq[i], n_color);
    }

    while(right < n) {
        cnt[seq[right]]++;
        if(cnt[seq[right]]==1) {
            w_color++;
        }
        right++;

        while(cnt[seq[left]] > 1) {
            cnt[seq[left]]--;
            left++;
        }

        if(w_color == n_color) {
            shortest = min(shortest, (right - left));
        }
    }

    cout << shortest << "\n";

    return 0;
}
