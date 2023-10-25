#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);
#define MAXN 100005

int t, n, k;
int tem[MAXN];

bool BS(int dis) {
    int num, range;
    num=1, range=dis;
    for(int i=0;i<n;i++) {
        if(range>=tem[i]) continue;
        else if(range<tem[i]) num++, range+=2*dis;
    }

    if(num > k) return false;
    else return true;
}

int main() {

    cin.sync_with_stdio(false), cin.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=0;i<n;i++) cin >> tem[i];

        sort(tem, tem+n);

        int s, e, m;
        s=0, e=n/2;
        while(s<e) {
            m=(s+e)/2;

            if(BS(m)) e=m;
            else s=m+1;
        }

        cout << s << "\n";
    }


    return 0;
}
