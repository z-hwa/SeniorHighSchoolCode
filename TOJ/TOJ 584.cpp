#include "bits/stdc++.h"
using namespace std;

/*
�ʺA�W��:[i][j]�A�Hi�����t�ƦC�������Aj�����t�ƦC�����t�A�����A�ಾ�C
�ಾ�ɻݭn�B�~�[�@�A�]����ӼƦr�]�O
*/

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

const int rf=20000, m=1e9+7;
int n, ans=0;
int arr[1005], tem[1005][40005];

int main() {
    AC;

    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    ans=n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            tem[i][arr[i]-arr[j]+rf]=((tem[i][arr[i]-arr[j]+rf]) + (tem[j][arr[i]-arr[j]+rf]) + 1) % m;
            ans = (ans + tem[j][arr[i]-arr[j]+rf] + 1) % m;
        }
    }

    cout << ans << "\n";

    return 0;
}
