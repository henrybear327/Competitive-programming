// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1998
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int bsearch(int* inp, int n, int val)
{
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        
        if(inp[mid] <= val)
            l = mid;
        else
            r = mid;
    }
    
    if(l == -1)
        return -1;
    return inp[l] == val ? l : -1;
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        int inp[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &inp[i]);
        sort(inp, inp + n);
        
        int t;
        scanf("%d", &t);
        
        int i1 = -1, i2 = -1;
        for(int i = 0; i < n; i++) {
            int ret = bsearch(inp, n, t - inp[i]);
            
            if(ret == -1)
                continue;
            
            if(i1 == -1 || i2 - i1 > abs(inp[i] - inp[ret])) {
                // printf("%d %d\n", i, ret);
                i2 = max(inp[ret], inp[i]);
                i1 = min(inp[ret], inp[i]);
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n", i1, i2);
    }
    
    return 0;
}