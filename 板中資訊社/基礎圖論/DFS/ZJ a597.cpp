#include <bits/stdc++.h>
using namespace std;

/*
graph basic bfs
*/

typedef long long ll;
const int N=505;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second

int n=0, m=0;
string tem[N];
int dx[5]={0, 1, 0, -1};
int dy[5]={1, 0, -1, 0};

int bfs(int a, int b, int zone) {
    tem[a][b]='X';
    queue<pii> q;
    q.push(pii(a, b));
    while(!q.empty()) {
        zone++;
        pii p=q.front();
        q.pop();

        for(int i=0, x, y;i<4;i++) {
            x=p.ff+dx[i], y=p.ss+dy[i];
            if(x>=0 && x<m && y>=0 && y<n && tem[x][y]=='J') q.push(pii(x, y)), tem[x][y]='X';
        }
    }

    return zone;
}

int main() {
    AC

    while(cin >> m >> n) {
        for(int i=0;i<m;i++) {
            cin >> tem[i];
        }

        int tim=0, ans=0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(tem[i][j]=='J') ans=max(bfs(i, j, 0), ans), tim++;
            }
        }

        cout << tim << " " << ans << "\n";
    }

    return 0;
}
