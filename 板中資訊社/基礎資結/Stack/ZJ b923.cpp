#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int st[MAXN], top=-1;

void push(int data) {
    st[++top]=data;
}

void pop() {
    if(top==-1) return;
    top--;
}

int query() {
    assert(top>-1);
    return st[top];
}

int main() {

    int n;
    cin >> n;

    while(n--) {
        int a;
        cin >> a;

        if(a==1) pop();
        else if(a==2) cout << query() << "\n";
        else {
            int b;
            cin >> b;
            push(b);
        }
    }

    return 0;
};
