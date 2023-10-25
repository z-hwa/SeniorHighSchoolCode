#include <bits/stdc++.h>
using namespace std;

/*
graph record every point's side_num
record root
tracing root to check
*/

typedef long long ll;
const int N=10000;
#define AC cin.sync_with_stdio(false), cin.tie(nullptr);

int a, b;
int id=1, root=-1;
int tree[N];
set<int> record;
bool is_tree=true;

bool cycle(int n, int root) {
    if(n==root) return false;

    int now=tree[n];
    while(true) {
        if(now==root) return false;
        else if(now==n) return true;

        now=tree[now];
    }
}

void clean_tem() {
    memset(tree, -1, sizeof(tree));
    record.clear();
    is_tree=true;
    root=-1;
    return;
}

int main() {

    AC

    while(cin >> a >> b) {
        if(a<0 && b<0) break;
        else {
            if(a==0 && b==0) {
                cout << "Case " << id++ << " is a tree.\n";
                continue;
            }

            clean_tem();

            record.insert(a), record.insert(b);
            tree[b]=a;

            while(cin >> a >> b) {
                if(a==0 && b==0) break;
                if(tree[b]==-1) {
                    tree[b]=a;
                }
                else is_tree=false;

                record.insert(a), record.insert(b);
            }

            for(auto it:record) {
                if(is_tree==false) break;
                if(tree[it]==-1) {
                    if(root==-1) root=it;
                    else is_tree=false;
                }
            }

            for(auto it:record) {
                if(is_tree==false) break;
                if(cycle(it, root)) is_tree=false;
            }

            if(is_tree==true) cout << "Case " << id++ << " is a tree.\n";
            else cout << "Case " << id++ << " is not a tree.\n";
        }
    }

    return 0;
}
