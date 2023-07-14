#include "bits/stdc++.h"
using namespace std;
/*
APCS
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, m, k;
int mp[105][105], knowx[505], knowy[505], kdirx[505], kdiry[505], num, die[505]={0}, cop[105][105], ans=0;

int main(){
    AC

    cin >> n >> m >> k;
    for(int i=0;i<k;i++) {
        cin >> knowx[i] >> knowy[i] >> kdirx[i] >> kdiry[i];
    }

    num=k;

    while(num > 0) {
        for(int i=0;i<k;i++) {
            if(die[i] == 1) continue;

            mp[knowx[i]][knowy[i]]=1;
        }

        memcpy(cop, mp, sizeof(mp));

        for(int i=0;i<k;i++) {
            if(die[i] == 1) continue;
            int nexx=knowx[i]+kdirx[i], nexy=knowy[i]+kdiry[i];

            if(nexx < 0 || nexx > n || nexy < 0 || nexy > m) {
                die[i]=1;
                num--;
            }
            else if(mp[nexx][nexy]==1) {
                die[i]=1;
                num--;
                cop[nexx][nexy]=0;
            }
            else {
                knowx[i]=nexx, knowy[i]=nexy;
            }
        }

        memcpy(mp, cop, sizeof(mp));
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mp[i][j]==1) ans++;
        }
    }

    cout << ans << "\n";

	return 0;
}
