#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define SIZE 1000001
#define MAX 550000
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int queens, timecount, solutions;
bool hc[12], hd1[23], hd2[23], cb[12][12];

void DFS(int now) {
    if(now == queens) {
        ++solutions;
        for(int i=0;i<queens;++i) {
            for(int j=0;j<queens;++j)
                cout << (cb[i][j] ? 'Q' : 'x');
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<queens;++i) {
        if(!hc[i] && !hd1[queens + now - i] && !hd2[now + i]) {
            hc[i] = hd1[queens + now - i] = hd2[now + i] = cb[now][i] = true;
            DFS(now+1);
            hc[i] = hd1[queens + now - i] = hd2[now + i] = cb[now][i] = false;
        }
    }
}

int main() {

    AC;

    while(cin >> queens) {
        if(queens == 0) break;
        if(timecount)
            cout << "\n";
        DFS(0), cout << solutions << "\n";
        solutions = 0, ++timecount;
    }

    return 0;
}
