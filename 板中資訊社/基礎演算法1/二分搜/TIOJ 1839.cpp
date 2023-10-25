#include "lib1839.h"

int tem[5005], loc[5005];

int main() {

    while(1) {
        int n=Initialize();

        for(int i=0;i<n;i++) loc[i]=-1;
        for(int i=0;i<n;i++){
            int record=tryCombination(tem); if(record==-1) record=n;
            bool presame = (record==i);
            int hight=n, low=0; bool ff=(record>i);
            while(low<hight-1) {
                int mid=(hight+low)/2;
                for(int j=low;j<mid;j++){
                    if(loc[j]==-1) tem[j]=(tem[j]+1)&1;
                }

                int re=tryCombination(tem); if(re==-1) re=n;
                bool cursame= (re==i);
                if(cursame!=presame) hight=mid;
                else low=mid;

                ff=(re>i);
                presame=cursame;
            }

            loc[low]=i;
            if(!ff) tem[low]=(tem[low]+1)&1;
        }

        answer(tem, loc);
    }

    return 0;
}

