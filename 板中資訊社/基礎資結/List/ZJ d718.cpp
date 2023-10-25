#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001
#define MAX 1001

int gn[SIZE];

int main() {
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, m, num, gc[MAX], deq, ncase=1;
    while(cin >> n) {
        memset(gc, 0, sizeof(gc));
        memset(gn, -1, sizeof(gn));

        for(int i=0;i<n;i++) {
            cin >> m;
            for(int j=0;j<m;j++) {
                cin >> num;
                gn[num] = i;
            }
        }

        list<int> L;
        list<int>::iterator itl, itg[MAX];
        string s;

        cout << "Line #" << ncase++ << "\n";

        while(cin >> s) {
            if(s=="ENQUEUE") {
                int num, i;
                cin >> num;
                i=gn[num];

                if(i>-1) {
                    if(gc[i]==0) {
                        L.push_back(num);
                        itg[i] = --L.end();
                    } else {
                        itl = itg[i];
                        itg[i] = L.insert(++itl, num);
                    }
                    gc[i]++;
                }else L.push_back(num);
            }else if(s=="DEQUEUE"){
                deq=*(L.begin());
                int i = gn[deq];
                if(i>-1) gc[i]--;
                cout << *(L.begin()) << "\n";
                L.erase(L.begin());
            }else if(s=="STOP")
                break;
        }
    }


    return 0;
}
