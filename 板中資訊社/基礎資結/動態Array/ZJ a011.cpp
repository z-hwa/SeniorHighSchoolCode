#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001
#define MAX 2050000

string word;
long long ans = 0;
bool status = 0;

int main() {

    while(getline(cin, word)) {
        ans = 0;
        //cout << "System: code->input '" << word << "'\n";
        for(int i=0;i<=word.size();i++) {
            if(!isalpha(word[i]) && status == 1) {
                cout <<  "System: code->plus '" << word[i-1] << "'\n";
                ans++;
                status = 0;
            }else if(isalpha(word[i]) && status == 0){
                status = 1;
            }
        }
        //cout << "System: code->ans '" << ans+1 << "'\n";
        cout << ans << "\n";
    }

    return 0;
}
