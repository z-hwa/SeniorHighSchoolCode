#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

ll n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    AC;

    cin >> n;
    while(n--) {
        int num, ut=9;
        cin >> num;

        while(ut>1) {
            if(num%ut==0) {
                pq.push(ut);
                num/=ut;
            }
            else {
                ut--;
            }
        }

        if(pq.size()==0 || num!=1) cout << "-1";

        while(pq.size()) {
            if(num==1) cout << pq.top();
            pq.pop();
        }

        cout << "\n";
    }

    return 0;
}
