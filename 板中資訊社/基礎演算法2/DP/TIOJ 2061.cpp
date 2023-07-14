#include "bits/stdc++.h"
using namespace std;

/*
DP:
對字串長度做處理，紀錄左邊界、右邊界逆向輸出
注意只有一個字元的情況
*/
#define ll long long
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

string s;
int n, dp[10001][10001], m=0, ml, mr;

int main(){
    AC

    cin >> s;
    n=s.length();

    if(n<10000) {
        memset(dp, 0, sizeof(dp));

        for(int i=0;i<n;i++) dp[i][i]=1;

        for(int len=1;len<=n;len++) {
            for(int i=0;i+len < n;i++) {
                if(s[i]==s[i+len]) dp[i][i+len]=dp[i+1][i+len-1]+2;
                else dp[i][i+len]=max(dp[i+1][i+len], dp[i][i+len-1]);

                if(dp[i][i+len] > m) {
                    ml=i, mr=i+len;
                    m=dp[i][i+len];
                }
            }
        }

        stack<char> v;
        while(m>0) {

            while(s[ml]==s[mr] && m>0) {
                cout << s[ml];
                if(m!=1) v.push(s[ml]);
                ml++, mr--, m-=2;
            }

            if(dp[ml+1][mr] > dp[ml][mr-1]) ml++;
            else mr--;
        }

        while(v.size()) {
            cout << v.top();
            v.pop();
        }

        if(n==1) cout << s;
    }
    else {
        int cnt[10]={};

        for(int i=0;i<n;i++) {
            cnt[s[i]-'0']++;
        }

        for(int i=0;i<10;i++) {
            if(cnt[i]>=1000) {
                for(int j=0;j<1000;j++) {
                    cout << (char)('0'+i);
                }
                cout << "\n";
                break;
            }
        }
    }

	return 0;
}
