#include "bits/stdc++.h"
using namespace std;
/*
dp: LCS backtrack
*/
typedef long long ll;
typedef pair<ll,ll> pll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

unordered_set<string> s[35][35];
int t=0, now=0, n=0, m=0, dp[35][35], used[35][35];
string a, b;
const string *res[100000+10];

int lcs(int i, int j) {
    if(used[i][j] < now) {
        used[i][j]=now;
        if(i==n || j==m) {
            dp[i][j]=0;
            s[i][j].insert("");
        }
        else if(a[i]==b[j]) {
            dp[i][j]=lcs(i+1, j+1)+1;

            for(auto x:s[i+1][j+1]) {
                s[i][j].insert(a[i]+x);
            }
        }
        else {
            int x=lcs(i+1, j), y=lcs(i, j+1);

            if(x>=y) {
                dp[i][j]=x;

                for(auto v:s[i+1][j]) {
                    s[i][j].insert(v);
                }
            }

            if(x<=y) {
                dp[i][j]=y;

                for(auto v:s[i][j+1]) {
                    s[i][j].insert(v);
                }
            }
        }
    }

    return dp[i][j];
}

bool cmp(const string *a,const string *b) {
    return *a<*b;
}

int main() {
    AC

    cin >> t;
    for(now=1;now<=t;now++) {

        for(auto &x:s) {
            for(auto &y:x) {
                y.clear();
            }
        }

        cin >> a >> b;
        n=a.size(), m=b.size();

        lcs(0, 0);

        cout << "Case #" << now << ": " << s[0][0].size() << "\n";

        int r=0;

        for(auto &x:s[0][0]) {
            res[r++]=&x;
        }

        sort(res, res+r, cmp);

        for(int i=0;i<r;i++) cout << *res[i] << "\n";
    }

	return 0;
}
