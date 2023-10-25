#include "bits/stdc++.h"
using namespace std;

/*
DP:
*/
#define int long long
#define N 105
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
int tmp[N][N];

signed main(){
	AC;

	while(cin >> n) {
        fill(&tmp[0][0], &tmp[105][105], 0);

        for(int i=1;i<=n;i++) cin >> tmp[i][i];

        for(int j=2;j<=n;j++) {
            for(int i=j-1;i>=1;i--) {
                for(int k=i;k<j;k++) {
                    tmp[i][j]=max(tmp[i][j], ((j-i+1) & 1 ? tmp[i][k]*tmp[k+1][j] : tmp[i][k]+tmp[k+1][j]));
                }
            }
        }


        cout << tmp[1][n] << "\n";
	}

	return 0;
}
