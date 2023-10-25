#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX 4000
#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

int n, len, w, ans = 0;
pair<int, int> p[MAX];

int main() {

    IOS;
    cin >> n >> len >> w;
    for(int i=0;i<n;i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p+n);

    for(int l=0, r=0;l<n && r<n;) {
        if(l==r) {
            ans = max(ans, (int)1);
            r++;
        }
        else if(p[r].first-p[l].first>w) {
            l++;
        }
        else {
            vector<pair<int, int>> v;
            for(int i=l;i<=r;i++) {
                v.push_back({p[i].second, p[i].first});
            }

            sort(v.begin(), v.end());

            int m=v.size();

            for(int L=0, R=0;L<m && R<m;) {
                if(L==R) R++;
                else if(v[R].first-v[L].first>len) L++;
                else {
                    ans = max(ans, R-L+1);
                    R++;
                }
            }

            r++;
        }
    }

    cout << ans << "\n";

    return 0;
}
