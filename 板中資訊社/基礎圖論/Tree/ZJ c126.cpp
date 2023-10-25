#include <bits/stdc++.h>
using namespace std;

/*
using left_tree to decide the leaf's direction
follow pre to define every point
*/

typedef long long ll;
const int N=100005;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

string pre, mid;
int refle[150]={0};
char rt[150]={'0'}, lt[150]={'0'};
char root;

void last(char root) {
    if(lt[root]!='!') last(lt[root]);
    if(rt[root]!='!') last(rt[root]);
    cout << root;
    return;
}

void putree(char leaf, char root) {

    if(refle[leaf] < refle[root]) {
        if(lt[root]!='!') putree(leaf, lt[root]);
        else lt[root]=leaf;
    }
    else if(refle[leaf] > refle[root]) {
        if(rt[root]!='!') putree(leaf, rt[root]);
        else rt[root]=leaf;
    }

    return;
}

int main() {

    AC
    while(cin >> pre >> mid) {
        for(int i=0;i<150;i++) {
            rt[i]='!';
            lt[i]='!';
        }

        for(int i=0;i<mid.length();i++) {
            refle[mid[i]]=i;
        }

        root=pre[0];
        for(int i=1;i<pre.length();i++) {
            putree(pre[i], root);
        }

        last(root);
        cout << "\n";
    }

    return 0;
}
