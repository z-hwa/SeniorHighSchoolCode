#include <bits/stdc++.h>
using namespace std;

#define N 40000

int seq[N], cnt[N];

int main() {

    int n, i;
    cin >> n;

    for(i=0;i<n;i++) {
        cin >> seq[i];
    }

    int ans=0, left=0, right=0;

    while(right < n) {

        cnt[seq[right]]++;

        while(cnt[seq[right]]>1) {
            cnt[seq[left]]--;

            left++;
        }

        right++;

        ans = max(ans, right - left);
    }

    cout << ans << "\n";

    return 0;
}
