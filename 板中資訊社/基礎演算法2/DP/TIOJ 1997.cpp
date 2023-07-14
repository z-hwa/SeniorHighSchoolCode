#include "bits/stdc++.h"
using namespace std;
/*
DP:
回朔dp[i][j], i=第i個, j=第幾組
*/
typedef long long lld;
typedef pair<int,int> PII;
#define FF first
#define SS second
const int N = 1000000 + 5;
const lld INF = 1LL<<40;

int arr[N];
lld dp[N][7];
PII ori[N][7];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, k; cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>arr[i];
	fill(dp[1], dp[n]+7, -INF);
	dp[1][1]=arr[1];
	for(int j=1;j<=k;j++){
		for(int i=j;i<n;i++){
			if(j&1){
				if(dp[i][j]+arr[i+1] > dp[i+1][j]){
					dp[i+1][j] = dp[i][j]+arr[i+1];
					ori[i+1][j] = {i, j};
				}
				if(i >= j and dp[i][j]-arr[i+1] > dp[i+1][j+1]){
					dp[i+1][j+1] = dp[i][j]-arr[i+1];
					ori[i+1][j+1] = {i, j};
				}
			}else{
				if(dp[i][j]-arr[i+1] > dp[i+1][j]){
					dp[i+1][j] = dp[i][j]-arr[i+1];
					ori[i+1][j] = {i, j};
				}
				if(i >= j and dp[i][j]+arr[i+1] > dp[i+1][j+1]){
					dp[i+1][j+1] = dp[i][j]+arr[i+1];
					ori[i+1][j+1] = {i, j};
				}
			}
		}
	}
	while(n!=0 and k!=0){
		int nn = ori[n][k].FF, kk = ori[n][k].SS;
		if(k!=kk and nn!=0) cout<<nn<<'\n';
		n=nn, k=kk;
	}
	return 0;
}
