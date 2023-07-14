#include <bits/stdc++.h>
using namespace std;

/*
dp bit
*/

typedef long long int ll;

#define SIZE 1000001
#define AC cin.sync_with_stdio(false), cin.tie(0);

ll n, dis[20][20], dp[20][100000];

void init() {
    for(ll i=0;i<20;i++)
        for(ll j=0;j<100000;j++)
            dp[i][j]=0;
}

ll gcd(ll a, ll b) {
    return b?gcd(b, a%b) : a;
}

int main() {

    while(cin >> n) {
        init();

        for(ll i=0;i<n;i++)
            for(ll j=i+1;j<n;j++) {
                cin >> dis[i][j];
                dis[j][i]=dis[i][j];
            }

        ll a1, a2, a3;
        a1=a2=a3=0;

        for(ll i=1;i<=n;i++) {
            for(ll s=1;s<(1<<n);s++) {
                ll c=0, k=s;
                while(k) {
                    if(k&1) c++;
                    k>>=1;
                }
                if(c!=i) continue;

                for(ll x=0;x<n;x++) {
                    if(s&(1<<x)) {
                        if(i==1) dp[x][s]=dis[x][0];

                        for(ll y=0;y<n;y++){
                            if(x!=y && (s&(1<<y)))
                                if(dp[x][s]==0 || dp[x][s] > dp[y][s ^ (1<<x)]+dis[x][y]) {
                                    dp[x][s]=dp[y][s ^ (1<<x)]+dis[x][y];
                                }
                        }
                    }
                }
            }
        }

        a1=dp[0][(1<<n)-1];

        init();

        for(ll i=1;i<=n;i++)
            for(ll s=1;s<(1<<n);s++) {
                ll c=0, k=s;
                while(k) {
                    if(k&1) c++;
                    k>>=1;
                }
                if(c!=i) continue;

                for(ll x=0;x<n;x++) {
                    if(s&(1<<x)) {
                        if(i==1) dp[x][s]=dis[x][0];

                        for(ll y=0;y<n;y++)
                            if(x!=y && (s&(1<<y)))
                                if(dp[x][s]==0 || dp[x][s] < dp[y][s ^ (1<<x)]+dis[x][y])
                                    dp[x][s]=dp[y][s ^ (1<<x)]+dis[x][y];

                    }
                }
            }

        a2=dp[0][(1<<n)-1];

        if(a2%a1==0)
            cout << a2/a1 << "\n";
        else {
            a3=gcd(a1, a2);
            cout << a2/a3 << "/" << a1/a3 << "\n";
        }
    }

    return 0;
}
