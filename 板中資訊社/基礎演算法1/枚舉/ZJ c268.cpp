#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

#define SIZE 1000001
#define MAX 550000
#define AC ios_base::sync_with_stdio(0), cin.tie(0);

int t;

int main() {
    AC

    cin >> t;
    while(t--) {
        int tem[45];
        int n, ans = 0;
        bool cant = true;
        cin >> n;

        if(n>45) {
            for(int i=0;i<n;i++) cin >> ws, cin.ignore(1e9, '\n');
            cout << "YES\n";
            continue;
        }

        for(int i=0;i<n;i++) cin >> tem[i];

        sort(tem, tem+n);

        for (int i = 0; i < n - 2 && cant; i++)
				for (int j = i + 1; j < n - 1 && cant; j++)
					for (int k = j + 1; k < n && cant; k++)
						if (tem[i] + tem[j] > tem[k])
							cant = false;

        if(!cant) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
