#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<pair<ll, int>>::iterator it_t;

#define MAX 100005
#define IOS cin.sync_with_stdio(false), cin.tie(nullptr);

int fac[31], n, k;
int a[MAX], b[MAX];
ll res;

//�N�G�i���C��1���Y���ȥͦ�
void init() {
    for(int i=0;i<31;i++)
        fac[i] = 1<<i;
}

int main() {

    IOS;
    init();
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
        if((a[i]&k)==a[i]) {
            res+=b[i];
        }
    }

    for(int i=30;i>=0;i--) {
        if(k&fac[i]) {
            int tmp = (k^fac[i]) | (fac[i]-1); //�Nk�H�G�i��覡�A�U���=1���ର0�A�e����1�A�p���@�ӥ����and���Ƶ���Ӽƪ̧Y�p��k
            ll ans = 0;
            for(int j=0;j<n;j++)
                if((a[j]&tmp)==a[j]) ans+=b[j];
            res=max(res, ans);
        }
    }

    cout << res << "\n";

    return 0;
}
