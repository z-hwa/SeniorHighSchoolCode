#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {

    int n, diff = 0, least = 1e9;
    cin >> n;
    int tem[n];
    for(int i=0;i<n;i++) {
        cin >> tem[i];

        diff = max(diff, tem[i] - least);
        least = min(tem[i], least);
    }

    cout << diff << "\n";

    return 0;
}
