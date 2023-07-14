#include <bits/stdc++.h>
using namespace std;

/*
*/

typedef long long ll;
const int N=100005;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

ll n, root;
ll tem[1005];
ll lt[1005]={0}, rt[1005]={0};

void last(ll root) {
    cout << tem[root] << " ";
    if(lt[root]!=0) last(lt[root]);
    if(rt[root]!=0) last(rt[root]);
}

void putree(ll index, ll root) {
    if(tem[index] > tem[root]) {
        if(rt[root]==0) rt[root]=index;
        else putree(index, rt[root]);
    }
    else if(tem[index] < tem[root]) {
        if(lt[root]==0) lt[root]=index;
        else putree(index, lt[root]);
    }

    return ;
}

int main() {

    AC
    while(cin >> n) {
        memset(lt, 0, sizeof(lt));
        memset(rt, 0, sizeof(rt));
        for(int i=0;i<n;i++) cin >> tem[i];

        root=0;

        for(int i=1;i<n;i++) putree(i, root);

        last(root);
        cout << "\n";
    }

    return 0;
}
