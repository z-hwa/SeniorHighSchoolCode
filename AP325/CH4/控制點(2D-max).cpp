#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct Point{
    LL x, y;
};

bool cmp(Point a, Point b){
    return a.x < b.x;
}

int main() {

    int n;
    cin >> n;

    Point tem[n];

    for(int i=0;i<n;i++) {
        cin >> tem[i].x;
    }

    for(int i=0;i<n;i++) {
        cin >> tem[i].y;
    }

    sort(tem, tem+n, cmp);

    stack<LL> pp;

    pp.push(1e9);

    for(int i=0;i<n;i++) {
        while(tem[i].y>=pp.top()){
            pp.pop();
        }

        pp.push(tem[i].y);
    }

    cout << pp.size() - 1 << "\n";

    return 0;
}
