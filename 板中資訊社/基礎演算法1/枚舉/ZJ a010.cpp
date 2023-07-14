#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

int n, last;
map<int , int> mp;

int main() {
    AC

    cin >> n;
    while(n>1) {
        for(int i=2;i<=n;i++) {
            if(n%i==0) {
                mp[i]++;
                n/=i;
                last = i;
                break;
            }
        }
    }

    for(int i=0;i<=last;i++) {
        if(mp.find(i) != mp.end()) {
            if(mp[i] > 1) cout << i << "^" << mp[i] << " ";
            else cout << i << " ";

            if(i != last)cout << "* ";
        }
    }

    return 0;
}
