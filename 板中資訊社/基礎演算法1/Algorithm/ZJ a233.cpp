#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

int n, tem[SIZE];

int main() {
    AC

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> tem[i];
    }

    sort(tem, tem+n);

    for(int i=0;i<n;i++) cout << tem[i] << "\n";

    return 0;
}
