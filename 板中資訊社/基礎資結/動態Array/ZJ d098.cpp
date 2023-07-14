#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZE 1000001
#define MAX 2050000

string s;
stringstream str;
ll sum, status = 0, num = 0, odi;
string ost;
ll tem[MAX], oop = 0;

int main() {

    while(getline(cin, s)) {
        status = 0, num = 0;
        oop = 0;
        str.str("");
        str.clear();

        for(int i=0;i<=s.size();i++) {
            if(status==1 && (s[i] == ' ' || i==s.size())) {
                //cout << "System: code->Plus '" << s[i-1] << "-" << oop << "'\n";

                tem[num] = oop;

                num++;
                status = 0;
                oop = 0;
            }else if(status==0 && s[i] != ' ') {
                status = 1;
            }

            if(!isdigit(s[i]) && s[i] != ' ') oop = 1;
        }

        //cout << "System: coed->showStatus '" << num << "'\n";

        str << s;
        for(int i=0;i<num;i++) {
            if(tem[i] == 0) {
                str >> odi;
                sum+=odi;
            }else {
                str >> ost;
            }
        }

        cout << sum << "\n";
    }

    return 0;
}
