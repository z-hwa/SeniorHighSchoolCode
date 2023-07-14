#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000

ll n, k;
ll hi[MAX], ans = 0, na, pos;
int bi[MAX];
deque<ll> city, index;

int main() {

    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &hi[i]);
    for(int i=0;i<n;i++) scanf("%d", &bi[i]);

    city.push_back(hi[0]);
    index.push_back(0);
    ans += bi[0];
    na = ans;
    pos = 0;
    //cout << ans << "\n";

    for(int i=1;i<n;i++) {
        while(city.size() && city.back() <= hi[i]) {
            //cout << "System: pop " << city.back() << "\n";
            na -= bi[index.back()];
            city.pop_back();
            index.pop_back();
        }

        city.push_back(hi[i]);
        index.push_back(i);
        na += bi[i];
        //cout << "System: push " << city.back() << "\n";

        while((index.back() - index.front()) >= k) {
            //cout << "System: pop " << city.front() << "\n";
            na -= bi[index.front()];
            city.pop_front();
            index.pop_front();
        }

        if(na > ans) pos = i;
        ans = max(na, ans);
        //cout << "System: ans:nan -> " << ans << ":" << na << "\n";
    }

    cout << pos+1 << " " << ans << "\n";

    return 0;
}
