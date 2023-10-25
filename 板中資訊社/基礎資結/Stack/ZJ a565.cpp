#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

stack <int> st;

int main() {

    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while(n--) {
        int ans=0;
        string cd;
        cin >> cd;

        for(int i=0;i<cd.size();i++) {
            if(cd[i]=='.') {}
            else if(cd[i]=='p') {
                st.push(i);
            }
            else if(cd[i]=='q') {
                if(!st.empty()) {
                    st.pop();
                    ans++;
                }
            }
        }

        cout << ans << "\n";

        while(!st.empty()) st.pop();
    }

    return 0;
}
