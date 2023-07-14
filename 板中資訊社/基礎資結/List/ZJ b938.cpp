#include <iostream>
using namespace std;

#define SIZE 1000001
int behind[SIZE], n, killtime;
bool died[SIZE];

int main() {
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> killtime;

    behind[n] = -1;
    for(int i=2;i<=n;++i) {
        behind[i-1] = i;
    }

    while(killtime--) {
        int choose;
        cin >> choose;
        if(behind[choose] == -1 || died[choose])
            cout <<  "0u0 ...... ?\n";
        else {
            cout << behind[choose] << "\n", died[behind[choose]] = true;
            behind[choose] = behind[behind[choose]];
        }
    }

    return 0;
}
