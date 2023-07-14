#include "bits/stdc++.h"
using namespace std;

/*
分治最近點對:分三種情況處理
兩個點:直接輸出
三個點:倆倆比較
多個點:x排序->分治->y排序(鴿籠理論)
*/

typedef long long ll;
#define int long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

struct point{
    double x, y;
};

bool cmp_x(point a, point b) {
    return a.x < b.x;
}

bool cmp_y(point a, point b) {
    return a.y < b.y;
}

int n;
point arr[50005], ans[2];

double dis(point a, point b) {
    double s = (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
    return sqrt(s);
}

double merge_sort(int l, int r) {

    if((r-l)==1) {
        ans[0].x=arr[l].x;
        ans[0].y=arr[l].y;
        ans[1].x=arr[r].x;
        ans[1].y=arr[r].y;

        return dis(arr[l], arr[r]);
    }
    else if((r-l)==2) {
        double d=1e9;
        for(int i=l;i<=r;i++) {
            for(int j=i+1;j<=r;j++) {
                double s=dis(arr[i], arr[j]);
                if(s < d) {
                    ans[0].x=arr[i].x;
                    ans[0].y=arr[i].y;
                    ans[1].x=arr[j].x;
                    ans[1].y=arr[j].y;
                    d=s;
                }
            }
        }
        return d;
    }
    else {
        int m = (l+r)/2;
        double d=0;
        vector<point> v;
        point tmp1[2], tmp2[2];
        double d1 = merge_sort(l, m);
        tmp1[0]=ans[0];
        tmp1[1]=ans[1];
        double d2 = merge_sort(m+1, r);
        tmp2[0]=ans[0];
        tmp2[1]=ans[1];

        if(d1<d2) {
            d=d1;
            ans[0]=tmp1[0];
            ans[1]=tmp1[1];
        }else {
            d=d2;
            ans[0]=tmp2[0];
            ans[1]=tmp2[1];
        }

        for(int i=l; i<=m;i++) {
            if((arr[m].x-d) <= arr[i].x) v.push_back(arr[i]);
        }
        for(int i=m+1; i<=r;i++) {
            if((arr[m].x+d) >= arr[i].x) v.push_back(arr[i]);
        }

        sort(v.begin(), v.end(), cmp_y);

        for(int i=0;i<v.size();i++) {
            for(int j=i+1;j<=i+7 && j<v.size();j++) {
                double s=dis(v[i], v[j]);
                if(s < d) {
                    ans[0].x=v[i].x;
                    ans[0].y=v[i].y;
                    ans[1].x=v[j].x;
                    ans[1].y=v[j].y;
                    d=s;
                }
            }
        }

        return d;
    }

}

signed main(){
	AC;

	while(cin >> n) {

        for(int i=0;i<n;i++) cin >> arr[i].x >> arr[i].y;
        sort(arr, arr+n, cmp_x);

        merge_sort(0, n-1);

        cout << fixed << setprecision(6) << dis(ans[0], ans[1]) << "\n";
	}

	return 0;
}
