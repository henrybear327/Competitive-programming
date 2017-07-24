// enumeration
// 0/1 DP

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        int inp[m];
        for(int i = 0; i < m; i++)
            scanf("%d", &inp[i]);
        
        int diff = n, who = 0, cnt = 0;
        for(int i = 1; i < (1 << m); i++) {
            int sum = 0, tot = 0;
            for(int j = 0; j < m; j++) {
                if((i >> j) & 1) {
                    sum += inp[j];
                    tot++;
                }
            }
            
            int tmp = n - sum;
            if(tmp >= 0 && tmp <= diff) {
                if(tot > cnt) {
                    who = i;
                    diff = tmp;
                    tot = cnt;
                }
            }
        }
        
        for(int j = 0; j < m; j++) {
            if((who >> j) & 1) {
                printf("%d ", inp[j]);
            }
        }
        printf("sum:%d\n", n - diff);
    }
    
    return 0;
}