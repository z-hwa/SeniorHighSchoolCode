#include "bits/stdc++.h"
using namespace std;

/*
DP:有限背包問題
透過拆分物品轉換成0/1背包問題
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct Ore{
    int w, v;
};

int n, c, dp[10005];
vector<Ore> v;
Ore tmp;

void Assign(int num) {
    if(num == 1) v.push_back(tmp);
    else {
        int nthp=1;
        Ore tmp2;
        while(num>0) {
            num-=nthp;

            if(num < 0) nthp+=num;

            tmp2.w=tmp.w*nthp;
            tmp2.v=tmp.v*nthp;
            v.push_back(tmp2);

            nthp*=2;
        }
    }

    return ;
}

int main(){

    AC
    cin >> n;
    for(int i=0, num;i<n;i++) {
        cin >> tmp.w >> tmp.v >> num;
        Assign(num);
    }
    cin >> c;

    fill(dp, dp+10005, 0);

    for(int num=0;num<v.size();num++) {
        for(int tot=c;tot>=v[num].w;tot--) {
            dp[tot]=max(dp[tot-v[num].w] + v[num].v, dp[tot]);
        }
    }

    cout << dp[c] << "\n";

	return 0;
}
