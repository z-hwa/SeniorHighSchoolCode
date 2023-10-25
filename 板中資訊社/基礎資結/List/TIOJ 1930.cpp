#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001
#define MAX 2000005

int t, n, m, a1;
int fr[MAX], bk[MAX];
vector<int> ans;
long long dump;

void put(int a, int b, int c) {
    if(c==1) {
        bk[fr[b]] = a;
        fr[a] = fr[b];
        fr[b] = a;
        bk[a] = b;
    }else {
        fr[bk[b]] = a;
        bk[a] = bk[b];
        bk[b] = a;
        fr[a] = b;
    }
}

void change(int a, int b, int c) {
    bk[fr[a]] = bk[b];
    fr[bk[b]] = fr[a];

    bk[fr[c]] = a;
    fr[a] = fr[c];
    fr[c] = b;
    bk[b] = c;
}

void dis(int a, long long b, int c) {
    if(c==1) {
        int now = a;
        for(int i=1;i<=b;i++) {
            if(now==0) {
                dump += b-i+1;
                break;
            }
            ans.emplace_back(now);
            bk[fr[now]] = bk[now];
            fr[bk[now]] = fr[now];
            now = fr[now];
        }
    }else {
        int now = a;
        for(int i=1;i<=b;i++) {
            if(now==n+1) {
                dump += b-i+1;
                break;
            }
            ans.emplace_back(now);
            bk[fr[now]] = bk[now];
            fr[bk[now]] = fr[now];
            now = bk[now];
        }
    }
}

void solve() {
    dump = 0;
    ans.clear();
    fill(fr, fr+MAX, 0);
    fill(bk, bk+MAX, 0);

    cin >> n >> m >> a1;
    bk[0] = a1, bk[a1] = n+1, fr[a1] = 0, fr[n+1] = a1;

    for(int i=1, k, a, b, c;i<=m;i++) {
        cin >> k >> a >> b >> c;
        if(k==1) put(a, b, c);
        else if(k==2) change(a, b, c);
        else dis(a, b, c);
    }

    cout << dump << "\n";
    for(auto i:ans) cout << i << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> t;

    while(t--) solve();

    return 0;
}
