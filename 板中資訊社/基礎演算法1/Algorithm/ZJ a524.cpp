#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

int n;

int main() {
    AC

    while(cin >> n) {
        int tem[n];
        for(int i=0;i<n;i++) tem[i] = n-i;

        do{

            for(int i=0;i<n;i++) cout << tem[i];
            cout << "\n";

        }while(prev_permutation(tem, tem+n));
    }


    return 0;
}
