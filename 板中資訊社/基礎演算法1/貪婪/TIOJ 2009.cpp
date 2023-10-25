#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, k, yes=0, tim=0;
int arr[10005];

int main() {
    AC;

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        if(num<arr[i]) arr[i]=num-arr[i]+9;
        else arr[i]=num-arr[i];
    }

    for(int i=0;i<n-k+1;i++) {
        if(arr[i]!=0) {
            tim+=arr[i];
            int tmp=arr[i];
            for(int j=0;j<k;j++) {
                arr[i+j]=(arr[i+j]-tmp+9)%9;
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(arr[i]!=0) {
            cout << "0\n";
            return 0;
        }
    }

    cout << tim << "\n";

    return 0;
}
