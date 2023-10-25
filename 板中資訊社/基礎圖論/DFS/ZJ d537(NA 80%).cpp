#include <bits/stdc++.h>
using namespace std;

/*
graph basic bfs
*/

typedef long long ll;
const int N=105;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

bool islegel(data ini) {
    if(ini.x>=0&&ini.x<fabic&&ini.y>=0&&ini.y<fabic) {
        if(ini.color == "R" && red_iswalk[ini.x][ini.y] == 0) return true;
        else if(ini.color == "Y"&& yellow_iswalk[ini.x][ini.y] == 0) return true;
        else if(ini.color == "B"&& blue_iswalk[ini.x][ini.y] == 0) return true;
        else return false;
    }
    else return false;
}

void bfs() {
    while(!q.empty()) {
        data ini, ano;
        ini = ano = q.front();

        q.pop();

        if(timesheet < ini.now_time) {
            timesheet=ini.now_time;
            ans[1]=max(ans[1], color_max[1]);
            ans[10]=max(ans[10], color_max[10]);
            ans[100]=max(ans[100], color_max[100]);
            ans[11]=max(ans[11], color_max[11]);
            ans[101]=max(ans[101], color_max[101]);
            ans[110]=max(ans[110], color_max[110]);
            ans[111]=max(ans[111], color_max[111]);
        }

        if(islegel(ini)) change(ini);

        for(int i=0;i<8;i++) {
            ano.x=ini.x+dirx[i], ano.y=ini.y+diry[i], ano.now_time=ini.now_time+1;
            if(islegel(ano)) {
                q.push(ano);
                change(ini);
            }
        }
    }
}

int main() {
    AC

    cin >> fabic;

    data ini;

    for(int i=0;i<3;i++) {
        cin >> ini.color >> ini.x >> ini.y;
        ini.now_time=1;
        q.push(ini);
    }

    bfs();

    string que;
    cin >> que;
    if(que=="R") cout << ans[1] << "\n";
    else if(que=="Y") cout << ans[10] << "\n";
    else if(que=="B") cout << ans[100] << "\n";
    else if(que=="P") cout << ans[101] << "\n";
    else if(que=="O") cout << ans[11] << "\n";
    else if(que=="G") cout << ans[110] << "\n";
    else if(que=="D") cout << ans[111] << "\n";

    return 0;
}
