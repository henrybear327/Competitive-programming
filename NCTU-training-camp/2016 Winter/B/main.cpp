#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        n++;
        int inp[n + 10];
        inp[0] = 0;
        for(int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            
            inp[i] = inp[i - 1] + tmp;
        }

        int q;
        scanf("%d", &q);
        n--;
        for(int i = 0; i < q; i++){
            int num;
            scanf("%d", &num);
            
            printf("%d\n", n - (int)(lower_bound(inp + 1, inp + n + 1, num) - inp)
                            + 1);
        }
    }
    
    
    return 0;
}