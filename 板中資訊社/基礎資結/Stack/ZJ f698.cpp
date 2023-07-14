#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

stack <long> tem;

int main() {

    string next;

    while(cin >> next) {

        if(isdigit(next[0]) || isdigit(next[1])) {
            tem.push(stoi(next));
        }else {
            long a, b;
            a=tem.top();
            tem.pop();
            b=tem.top();
            tem.pop();

            if(next[0]=='*') tem.push(b*a);
            else if(next[0]=='/') tem.push(b/a);
            else if(next[0]=='+') tem.push(b+a);
            else if(next[0]=='-')tem.push(b-a);
        }

    }

    cout << tem.top() << "\n";

    return 0;
}
