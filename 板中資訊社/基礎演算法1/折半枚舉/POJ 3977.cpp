#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef vector<pair<ll, int>>::iterator it_t;

#define MAX 4000
#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
ll number[36];
vector<pair<ll, int>> v1, v2;
pair<ll, int> ans;

void Enumerate(vector<pair<ll, int>>& v, ll sum, int st, int ed, int cnt) {
    if(st==ed) {
        v.push_back({sum, cnt});
        return;
    }

    Enumerate(v, sum+number[st], st+1, ed, cnt+1);
    Enumerate(v, sum, st+1, ed, cnt);
}

void Update(ll s, int num) {
    if(num == 0) return;
    if(s < 0) s = -s;

    pair<ll, int> p = {s, num};
    if(p<ans) {
        ans = p;
    }
}

int main() {

    IOS;
    while(cin >> n) {
        if(n==0) break;

        v1.clear(), v2.clear();

        for(int i=0;i<n;i++) cin >> number[i];
        ans = pair<ll, int>(1e9, 1e9);

        Enumerate(v1, 0, 0, n/2, 0);
        Enumerate(v2, 0, n/2, n, 0);

        for(it_t i=v1.begin();i!=v1.end();i++) {
            Update(i->first, i->second);
        }
        for(it_t i=v2.begin();i!=v2.end();i++) {
            Update(i->first, i->second);
        }

        sort(v2.begin(), v2.end());
        for(it_t i=v1.begin();i!=v1.end();i++) {
            it_t j=lower_bound(v2.begin(), v2.end(), pair<ll, int>(-(i->first), 0));
            if(j != v2.end())
                Update(i->first+j->first, i->second+j->second);
            if(j-- != v2.begin())
                Update(i->first+j->first, i->second+j->second);
        }

        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
