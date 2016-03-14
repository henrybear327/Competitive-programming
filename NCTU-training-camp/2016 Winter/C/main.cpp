#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        int inp[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &inp[i]);
        sort(inp, inp + n);
        reverse(inp, inp + n);
        
        stack<int> s[3];
        for(int i = 0; i < n; i++)
            s[0].push(inp[i]);
        
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            char sss[10];
            scanf("%s", sss);
            
            if(sss[0] == 'm') {
                int a, b;
                scanf("%d %d", &a, &b);
                a--;
                b--;
                
                if(s[a].empty()) {
                    printf("But %d is empty!\n", a + 1);
                } else if(s[b].empty() || 
                    (s[b].empty() == false && s[a].top() < s[b].top()) ) {
                    s[b].push(s[a].top());   
                    s[a].pop();
                } else {
                    printf("Illegal Move\n");
                }
            } else {
                int a;
                scanf("%d", &a);
                a--;
                if(s[a].empty())
                    printf("But %d is empty!\n", a + 1);
                else
                    printf("%d\n", s[a].top());
            }
        }
    }

    return 0;
}