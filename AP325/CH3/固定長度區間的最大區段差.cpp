#include <bits/stdc++.h>;
using namespace std;

typedef long long LL;
#define MAXN 200010

int seq[MAXN];
deque<int> max_q, min_q;

void put_max(int i) {
    while(!max_q.empty() && seq[max_q.back()]<=seq[i]) {
        max_q.pop_back();
    }

    max_q.push_back(i);
}

void put_min(int i) {
    while(!min_q.empty() && seq[min_q.back()]>=seq[i]) {
        min_q.pop_back();
    }

    min_q.push_back(i);
}

int main() {
    int n, L, i, j, max_diff=0;
    cin >> n >> L;

    for(i=0;i<n;i++) {
        cin >> seq[i];
    }

    put_max(0);
    put_min(0);

    for(i=1;i<n;i++) {

        if(max_q.front()<=i-L)
            max_q.pop_front();
        put_max(i);

        if(min_q.front()<=i-L)
            min_q.pop_front();
        put_min(i);

        int diff = seq[max_q.front()] - seq[min_q.front()];
        max_diff= max(max_diff, diff);
    }

    cout << max_diff << endl;

    return 0;
}
