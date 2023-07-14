#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, ans = 0;
    cin >> n;

    priority_queue <int, vector<int>, greater<int>> tem;

    for(int i=0;i<n;i++) {
        int num;
        cin >> num;

        tem.push(num);
    }

    for(int i=0;i<n-1;i++) {
        int m;
        m = tem.top();
        tem.pop();
        m += tem.top();
        tem.pop();

        tem.push(m);
        ans += m;
    }

    cout << ans << "\n";

    return 0;
}
