#include <bits/stdc++.h>
using namespace std;

/*
graph record every stack's branch
star_num = leaf_num
*/

typedef long long ll;
const int N=100005;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

string s;
stack<int> st;
int tem[N];

int main() {

    AC
    while(cin >> s) {
        int cros=0, star=0, degre=0, mc=0;
        memset(tem, 0, sizeof(tem));
        st.push(0);

        for(auto i:s) {
            if(i=='(') {
                st.top()++;
                st.push(0);
                cros++;
            }
            else if(i==')') {
                degre=max(degre, st.top());
                st.pop();
                cros--;
            }

            mc=max(mc, cros);

            if(i=='*') {
                star++;
                st.top()++;
            }
        }

        cout << star << " " << mc+1 << " " << degre << "\n";
    }


    return 0;
}
