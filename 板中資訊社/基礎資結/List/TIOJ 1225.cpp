#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001
#define MAX 2050000

int main() {

	stack<long long> st;
	long long n, r, ans = 0;
	cin >> n;
	while(n--) {
        cin >> r;
        while(st.size() && r > st.top()) {
            st.pop();
            if(st.size()) ans += min(r, st.top());
            else ans+=r;
        }
        st.push(r);
	}
	while(st.size()>1) {
        st.pop();
        ans += st.top();
	}
	cout << ans << "\n";

    return 0;
}
