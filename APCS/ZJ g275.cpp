#include "bits/stdc++.h"
using namespace std;
/*
APCS
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n;
int arr[5][10];
int rule[5];

int main(){
    AC

    cin >> n;
    while(n--) {
        memset(rule, 0, sizeof(rule));

        for(int i=1;i<=7;i++) cin >> arr[0][i];
        for(int i=1;i<=7;i++) cin >> arr[1][i];


        bool isbad=false;

        for(int i=0;i<=1;i++) {
            if(arr[i][2]==arr[i][4]) {
                isbad=true;
                rule[1]=1;
                break;
            }

            if(arr[i][2]!=arr[i][6]) {
                isbad=true;
                rule[1]=1;
                break;
            }
        }

        if(arr[0][7]!=1 || arr[1][7]!=0) {
            isbad=true;
            rule[2]=1;
        }

        for(int i=2;i<=6;i+=2) {
            if(arr[0][i]==arr[1][i]) {
                isbad=true;
                rule[3]=1;
                break;
            }
        }

        if(isbad==false) cout << "None\n";
        else {
            for(int i=1;i<=3;i++) {
                if(rule[i]==1) cout << (char) ('A'+i-1);
            }
            cout << "\n";
        }
    }

	return 0;
}
