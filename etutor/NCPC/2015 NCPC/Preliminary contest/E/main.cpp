#include <bits/stdc++.h>

using namespace std;

int table[1024999];

int main()
{
    int goal;
    int n;
    while(scanf("%d %d",&goal,&n) == 2) {
        int a[n];
        memset(table,0,sizeof(table));
        for(int i=0; i<n; i++) {
            scanf("%d",&a[i]);
        }
        int ans = 0;
        int max = 0;
        table[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=max; j>=0; j--) {
                if(j+a[i]>goal)continue;
                if(table[j]) {
                    if(abs((j+a[i])-goal)<abs(ans-goal)) {
                        ans = j+a[i];
                    }
                    table[j+a[i]] = 1;
                    if((j+a[i])>max)
                        max = j+a[i];
                }
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
