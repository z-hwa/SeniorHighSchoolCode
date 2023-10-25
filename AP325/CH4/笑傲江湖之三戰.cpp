#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, ans=0;
    cin >> n;
    int enemy[n], our[n];

    for(int i=0;i<n;i++) {
        cin >> enemy[i];
    }

    for(int i=0;i<n;i++) {
        cin >> our[i];
    }

    sort(enemy, enemy+n);
    sort(our, our+n);

    for(int i=0, j=0;i<n;i++) {
        if(enemy[j] < our[i]) {
            j++;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
