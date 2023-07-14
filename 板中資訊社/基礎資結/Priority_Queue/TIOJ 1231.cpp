#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 10000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

struct food{
    ll cal, sl;
};

struct cmp{
    bool operator() (food a, food b) {
        if(a.sl == b.sl) return a.cal < b.cal;
        else return a.sl < b.sl;
    }
};

struct cmp_2{
    bool operator() (food a, food b) {
        return a.cal < b.cal;
    }
};

ll n, k, ans = 0;
food prepare;
priority_queue<food, vector<food>, cmp> pq;
priority_queue<food, vector<food>, cmp_2> tl;

int main() {
    AC

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> prepare.cal >> prepare.sl;
        pq.push(prepare);
    }

    cin >> k;

    while(k) {
         while(pq.size() && pq.top().sl > k) {
            tl.push(pq.top());
            pq.pop();
         }

         ll p = -1, t = -1;

         //cout << pq.top().sl << " " << pq.top().cal << "\n";
         if(pq.size() && pq.top().sl == k) p = pq.top().cal, pq.pop();
         if(tl.size()) t = tl.top().cal, tl.pop();

         //cout << p << " " << t << "\n";
         ans += max(p, t);
         k--;
    }

    cout << ans << "\n";

    return 0;
}
