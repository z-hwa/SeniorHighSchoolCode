#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);
#define MAXN 100000

int x, tem[MAXN];
int n, k;

bool f(int id) {
    if(tem[id]>=x) return true;
    else return false;
}

int Binary_search(int l, int r) {
    int m;
    while(l<r) {
        m=(l+r)/2;
        if(f(m)==true) r=m;
        else l=m+1;
    }

    return l;
}

int main() {

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> tem[i];

    int que, ans;

    while(k--) {
        cin >> que;
        x=que;
        ans=Binary_search(0, n);
        if(tem[ans]==que) cout << ans+1 << "\n";
        else cout << "0\n";
    }

    return 0;
}
