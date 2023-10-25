#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX 110000
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, q;

int main() {

    AC;

    cin >> n >> q;

    int tem[n], k;

    for(int i=0;i<n;i++) {
        cin >> tem[i];
    }

    sort(tem, tem+n);

    for(int i=0;i<q;i++) {
        cin >> k;
        int left = 0, right = 1;
        while(right < n) {
            if(tem[right] - tem[left] == k) break;
            if(tem[right] - tem[left] < k) right++;
            else left++;

            if(left==right) right++;
        }
        if(tem[right] - tem[left] == k)  cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
