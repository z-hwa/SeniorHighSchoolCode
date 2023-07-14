#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define SIZE 1000001
#define MAX 550000
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int que, cas, total;
int ans = 0;
bool row[100], sln[100], slp[100];
int slncas[100], slpcas[100];

void DFS(int i) {
    if(i == total) {
        ans++;
        return;
    }

    for(int j=0;j<total;j++) {
        if(!row[j] && !sln[j-i+total-1] && !slp[j+i]) {
            if(que && !slncas[j-i+total-1] && !slpcas[j+i]) {
                row[j] = sln[j-i+total-1] = slp[j+i] = true;
                que--;
                DFS(i+1);
                que++;
                row[j] = sln[j-i+total-1] = slp[j+i] = false;
            }
            if(cas) {
                row[j] = true, slncas[j-i+total-1]++, slpcas[j+i]++;
                cas--;
                DFS(i+1);
                cas++;
                row[j] = false, slncas[j-i+total-1]--, slpcas[j+i]--;
            }
        }
    }
}

int main() {

    AC;

    cin >> que >> cas;
    total = que + cas;
    DFS(0);

    cout << ans << "\n";

    return 0;
}
