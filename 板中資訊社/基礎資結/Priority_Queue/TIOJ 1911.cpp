#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 10000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

priority_queue<ll> bi;
priority_queue<ll, vector<ll>, greater<ll>> sm;
unordered_map<ll, ll> m;
ll n;

int main() {

    while(cin >> n) {
        if(n==-1) {
            while(sm.size() && !m[sm.top()]) sm.pop();
            if(sm.size()) cout << sm.top() << " ", m[sm.top()]--, sm.pop();
        }else if(n==-2) {
            while(bi.size() && !m[bi.top()]) bi.pop();
            if(bi.size()) cout << bi.top() << " ", m[bi.top()]--, bi.pop();
        }else {
            m[n]++, bi.push(n), sm.push(n);
        }
    }

    return 0;
}
