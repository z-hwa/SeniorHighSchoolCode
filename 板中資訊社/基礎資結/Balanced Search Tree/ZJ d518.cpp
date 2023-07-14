#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 10000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

int n, num = 1;
map<string, int> mp;
string use;
pair<string, int> pa;

int main() {
    AC

    cin >> n;

    while(n--) {
        cin >> use;

        if(mp.find(use) != mp.end()) {
            cout << "Old! " << mp[use];
        }else {
            pa.first = use;
            pa.second = num, num++;
            mp.insert(pa);
            cout << "New! " << mp[use];
        }

        if(n!=0) cout << "\n";
    }

    return 0;
}
