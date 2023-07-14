#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, k;

int GCD(int n, int k) {
    if(n==0) return k;
    return GCD(k%n, n);
}

int main() {

    AC

    cin >> n >> k;
    cout << GCD(min(n ,k), max(n, k));

    return 0;
}
