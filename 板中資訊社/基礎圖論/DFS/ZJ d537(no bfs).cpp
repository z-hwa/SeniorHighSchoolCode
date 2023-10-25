#include <bits/stdc++.h>
using namespace std;

/*
every times change and count the target color
*/

typedef long long ll;
const int N=105;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int boardsize=0, encode[128];
int board[N][N]={0}, tem[N][N]={0};
bool change[N][N]={0};
int target=0, x, y;
int targetamount=0, lastamount=0;
int dist=0, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }, dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
char color='N';

static const auto Initialize = [] {
    AC
    encode['Y']=1, encode['B']=2, encode['G']=3;
    encode['R']=4, encode['O']=5, encode['P']=6;
    encode['D']=7;
    return nullptr;
}();

int main() {

    cin >> boardsize;
    for(int i=0;i<3;i++) {
        cin >> color >> x >> y;
        x++, y++;
        change[x][y]=true;
        board[x][y]=encode[color];
    }
    cin >> color;
    target=encode[color];
    for(int i=1;i<=boardsize;i++)
        for(int j=1;j<=boardsize;j++)
            if(board[i][j]==target)
                targetamount++;
    while(lastamount <= targetamount) {
        if(dist==boardsize) break;
        lastamount=targetamount;

        memset(tem, 0, sizeof(tem));
        for(int i=1;i<=boardsize;i++)
            for(int j=1;j<=boardsize;j++){
                tem[i][j] |= board[i][j];
                if(change[i][j]) {
                    for(int k=0;k<8;k++) {
                        tem[i+dx[k]][j+dy[k]] |= board[i][j];
                    }
                }
            }

        memset(change, false, sizeof(change));
        for(int i=1;i<=boardsize;i++)
            for(int j=1;j<=boardsize;j++){
                if(board[i][j] != tem[i][j]) {
                    if(board[i][j]==target) targetamount--;
                    else if(tem[i][j]==target) targetamount++;

                    board[i][j]=tem[i][j], change[i][j]=true;
                }
            }
        dist++;
    }

    cout << lastamount << "\n";

    return 0;
}
