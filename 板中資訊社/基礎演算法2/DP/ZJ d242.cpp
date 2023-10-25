#include "bits/stdc++.h"
using namespace std;
/*
DP:LIS
記錄每一個數值，所放位置的長度逆推
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int arr[500005], ans[500005];

int main(){
    AC

    int n, i=0, j=0;
    vector<int> lis;

    while(cin >> n) {
        arr[i]=n;
        i++;
    }

    int lon=0;
    while(j!=i) {
        if(lis.size()==0 || arr[j] > lis.back()) {
            lis.push_back(arr[j]);
            lon++;
            ans[j]=lon;
        }
        else {
            int index=lower_bound(lis.begin(), lis.end(), arr[j])-lis.begin();
            lis[index]=arr[j];
            ans[j]=index+1;
        }

        j++;
    }

    cout << lon << "\n";
    cout << "-\n";

    vector<int> las;
    for(i=n-1;i>=0;i--) {
        if(ans[i]==lon) {
            las.push_back(arr[i]);
            lon--;
        }
    }
    reverse(las.begin(), las.end());
    for(i=0;i<las.size();i++) {
        cout << las[i] << "\n";
    }

	return 0;
}
