#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define SIZE 1000001
#define MAX 550000
#define AC cin.sync_with_stdio(false), cin.tie(0);

int g[9][9], r[9][9], c[9][9], b[3][3][9];
map<char, int> ci;
map<int, char> ic;
string st = "ROYGBIPLW", s;
vector<int> ans[9];

void Find(int x, int y) {
    if(x==9) {
        for(int i=0;i<9;i++) {
            for(int j:ans[i]) {
                cout << ic[j];
            }
            cout << "\n";
        }
        return ;
    }

    if(g[x][y] != -1) {
        if(y==8) Find(x+1, 0);
        else Find(x, y+1);
    }
    else {
        for(int i=0;i<9;i++) {
            if(!r[x][i] && !c[y][i] && !b[x/3][y/3][i]) {
                r[x][i] = 1;
                c[y][i] = 1;
                b[x/3][y/3][i] = 1;
                ans[x].push_back(i);
                if(y==8) Find(x+1, 0);
                else Find(x, y+1);
                r[x][i] = 0;
                c[y][i] = 0;
                b[x/3][y/3][i] = 0;
                ans[x].pop_back();
            }
        }
    }
}

int main() {

    AC;

    for(int i=0;i<9;i++) {
        ci[st[i]] = i;
        ic[i] = st[i];
    }

    for(int i=0;i<9;i++) {
        cin >> s;
        for(int j=0;j<9;j++) {
            if(s[j] != '*') {
                int tmp = ci[s[j]];
                g[i][j] = tmp;
                r[i][tmp] = 1;
                c[j][tmp] = 1;
                b[i/3][j/3][tmp] = 1;
            }
            else g[i][j] = -1;
        }
    }

    Find(0, 0);

    return 0;
}
