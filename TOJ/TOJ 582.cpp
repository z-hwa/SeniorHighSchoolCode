#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct pos{
    int x, y;
    int cost;

    void Set() {
        cost=0;
    }
};

int n, m, dx[4]={1,0,1,0}, dy[4]={0,1,0,1}, ans=1e9;
char Map[1005][1005];
bool iswalk[1005][1005];
queue<pos> q;
pos p;

bool che(int x, int y, int step) {
    if(x>=0 && x<n && y>=0 && y<m) {
        if(iswalk[x][y]==false) {
            if(Map[x][y]=='.') {
                iswalk[x][y]=true;
                return true;
            }
            else if(Map[x][y]=='E') {
                ans=min(step, ans);
                iswalk[x][y]=true;
                return true;
            }
        }
    }

    return false;
}

void extend(int x, int y, int step) {
    int nx, ny;
    for(int i=0;i<4;i++) {
        nx=x+dx[i];
        ny=y+dy[i];

        if(che(nx, ny, step+1)) {
            p.x=nx, p.y=ny, p.cost=step+1;
            q.push(p);
        }
    }
    return ;
}

int main() {
    AC;

    memset(iswalk, false, sizeof(iswalk));

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> Map[i][j];

            if(Map[i][j]=='V') {
                p.x=i, p.y=j;
                q.push(p);
                iswalk[i][j] = true;
            }
        }
    }

    while(q.size()) {
        extend(q.front().x, q.front().y, q.front().cost);
        q.pop();
    }

    if(ans==1e9) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}
/*
. V . .
. . T .
. . . .
. . # E
*/
