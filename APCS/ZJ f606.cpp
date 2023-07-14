#include "bits/stdc++.h"
using namespace std;
/*
APCS
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, m ,k;
int StoC[55][55], CtoC[55][55], fun[55][55], price[55], ans=1e9;

int main(){
    AC

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin >> StoC[i][j];

    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++) cin >> fun[i][j];

    for(int i=0;i<k;i++) {
        memset(CtoC, 0, sizeof(CtoC));

        for(int j=0;j<n;j++) {
            int Spos=fun[i][j];
            for(int q=0;q<m;q++) {
                int Cdem=StoC[j][q];

                CtoC[Spos][q]+=Cdem;
            }
        }

        for(int j=0;j<m;j++) {
            for(int q=0;q<m;q++) {
                if(j==q) price[i]=price[i]+CtoC[j][q];
                else {
                    if(CtoC[j][q] <= 1000) price[i]=price[i]+CtoC[j][q]*3;
                    else {
                        price[i]=price[i]+3000;
                        price[i]=price[i]+(CtoC[j][q]-1000)*2;
                    }
                }
            }
        }

        ans=min(ans, price[i]);
    }

    cout << ans << "\n";

	return 0;
}
