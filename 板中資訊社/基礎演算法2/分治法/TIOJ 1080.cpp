#include "bits/stdc++.h"
using namespace std;

/*
分治逆序:將問題拆分成子問題
運算中透過排序(單調性)，降低算法big-O
*/

typedef long long ll;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int n, arr[2000100], tmp[2000100], ans=0, tim=1;

void cct(int l,int r){
	int mid=(l+r)>>1;
	for(int i=l,j=mid+1,k=l ; k<=r ; k++){
		if(i>mid)
			tmp[k]=arr[j++];
		else if(j>r)
			tmp[k]=arr[i++];
		else if(arr[i]<=arr[j])
			tmp[k]=arr[i++];
		else{
			ans+=(mid-i+1);
			tmp[k]=arr[j++];
		}
	}
	for(int i=l ; i<=r ; i++)
		arr[i]=tmp[i];
}

void ct(int l,int r){
	int mid=(l+r)>>1;
	if(l==r)
		return;
	ct(l,mid);
	ct(mid+1,r);
	cct(l,r);
}

signed main(){
	AC;
	while(cin>>n && n){
		ans=0;
		for(int i=0 ; i<n ; i++){
			cin>>arr[i];
		}
		ct(0,n-1);
		cout<<"Case #"<<tim++<<": "<<ans<<'\n';
	}
	return 0;
}
