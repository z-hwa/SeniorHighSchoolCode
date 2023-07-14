#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

stack <int> tem;

int n;

void Count() {
    int num;
    while(cin >> num) {
        if(num==0) {
            return;
        }
        else {
            int ans[n];
            ans[0]=num;
            for(int i=1;i<n;i++) cin >> ans[i];

            for(int i=1, j=0;i<=n;i++) {
                tem.push(i);

                while(!tem.empty() && tem.top()==ans[j]) {
                    tem.pop();
                    j++;
                }
            }

            if(tem.empty()) cout << "Yes\n";
            else cout << "No\n";

            while(!tem.empty()) tem.pop();
        }
    }
}

int main() {

    while(cin >> n) {
        if(n==0) break;
        Count();
    }

    return 0;
}
