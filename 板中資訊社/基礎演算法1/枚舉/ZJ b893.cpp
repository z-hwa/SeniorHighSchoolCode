#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios::sync_with_stdio(0), cin.tie(0);

ll po[81][5];
ll a, b, c, d, e, f, fa, fb, noans = 1;

int main() {
    AC

    for(int i=-40;i<=40;i++) {
        po[40+i][0] = i;
        po[40+i][1] = i*i;
        po[40+i][2] = po[40+i][1] * i;
        po[40+i][3] = po[40+i][2] * i;
        po[40+i][4] = po[40+i][3] * i;
    }

    while(cin >> a >> b >> c >> d >> e >> f) {
        if(a || b || c || d || e || f) {
            noans = 1;
            fa = a * po[0][4] + b * po[0][3] + c * po[0][2] + d * po[0][1] + e * po[0][0] + f;
            for(int i=1;i<=80;i++) {
                fb = a * po[i][4] + b * po[i][3] + c * po[i][2] + d * po[i][1] + e * po[i][0] + f;
                if(!fb) {
                    cout << po[i][0] << " " << po[i][0] << "\n", noans = 0;
                }
                else if((fa^fb) < 0 && fa){
                    cout << po[i-1][0] << " " << po[i][0] << "\n", noans = 0;
                }
                fa = fb;
            }
            if(noans) cout << "N0THING! >\\\\\\<\n";

        }else {
            cout << "Too many... = =\"\n";
        }
    }

    return 0;
}
