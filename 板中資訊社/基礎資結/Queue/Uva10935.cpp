#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
typedef long long LL;

queue<int> qe;
string ans;

int main() {

    std::ios::sync_with_stdio(false);

    int n;
    bool st=true;

    while(cin >> n) {
        if(n==0) {
            cout << "\n";
            break;
        }
        else {
            if(st) st = false;
            else ans += "\n";
        }

        for(int i=1;i<=n;i++) qe.push(i);

        ans += "Discarded cards:";

        while(qe.size()>1) {
            if(qe.size()>2) {
                ans += " ";
                ans += to_string(qe.front());
                ans += ",";
            }
            else {
                ans += " ";
                ans += to_string(qe.front());
                ans += "\n";
            }

            qe.pop();
            qe.push(qe.front());
            qe.pop();
        }

        if(n==1) ans += "\n";

        ans += "Remaining card: ";
        ans += to_string(qe.front());
        while(!qe.empty()) qe.pop();
    }

    cout << ans;

    return 0;
}
