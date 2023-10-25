#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);
typedef unsigned long long int in;

in record[MAXN] = {0};
in a, b;

int trace_back(in a, in b, in k) {
    if(a==b) return 1;

    if(a>b) {
        return trace_back(a-b, b, k)*2;
    }
    else if(a<b) {
        return trace_back(b, a, k)+1;
    }

    return -1;
}

/*
�p�GA==B�A�פ�
�P�_AB�j�p>���JA-B,B��B,A
�ھ�AB�j�p>��K�Ȱ��ާ@
*/
int main() {

    while(cin >> a >> b) {
        cout << trace_back(a, b, 0) << "\n";
    }


    return 0;
}
