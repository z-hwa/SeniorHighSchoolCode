#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Line{
    LL left, right;
};

bool cmp(Line a, Line b){
    return a.left < b.left;
}

int main() {

    int n;
    LL ans = 0;
    cin >> n;

    Line tem[n];

    for(int i=0;i<n;i++) {
        cin >> tem[i].left >> tem[i].right;
    }

    sort(tem, tem+n, cmp);
    Line last = tem[0];

    for(int i=0;i<n;i++) {
        if(last.right < tem[i].left) {
            ans += last.right-last.left;
            last = tem[i];

            continue;
        }

        last.right = max(tem[i].right, last.right);
    }

    ans += last.right - last.left;

    cout << ans << "\n";

    return 0;
}
