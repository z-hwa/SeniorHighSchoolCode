#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
typedef long long LL;

stack <LL> st, st1, num;

LL n, ans=0, a;

int main() {

    std::ios::sync_with_stdio(false);
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> a;
        while(!st.empty() && st.top()<a) {
            ans+=st1.top();
            st1.pop();
            st.pop();
        }
        if(!st.empty() && st.top()==a) {
            ans+=st1.top();
            st1.top()++;
        }
        else {
            st.push(a);
            st1.push(1);
        }
        if(st.size() > 1)ans++;
    }

    cout << ans*2 << "\n";

    return 0;
}
