#include<bits/stdc++.h>
using namespace std;

int n;

void Move(int n, char a, char b) {
    cout << "Move ring " << n << " from " << a << " to " << b << "\n";
    return ;
}

void Sove(int n, char a, char b, char c) {
    if(n==1) {Move(1, a, c); return ;};
    Sove(n-1, a, c, b);
    Move(n, a, c);
    Sove(n-1, b, a, c);
}

int main()
{
    while(cin >> n) {

        Sove(n, 'A', 'B', 'C');
        cout << "\n";
    }

    return 0;
}
