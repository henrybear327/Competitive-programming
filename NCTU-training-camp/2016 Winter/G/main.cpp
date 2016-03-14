#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        queue<int> q[100010];
        queue<int> order;
        bool exist[100010] = {false};
        for(int i = 0; i < n; i++) {
            char inp[100];
            scanf("%s", inp);
            
            if(inp[1] == 'u') {
                int a, b;
                scanf("%d %d", &a, &b);
                
                if(exist[b] == false) {
                    order.push(b);
                    exist[b] = true;
                    
                    q[b].push(a);
                } else {
                    q[b].push(a);
                }
            } else {
                int top = order.front();
                    
                printf("%d\n", q[top].front());
                q[top].pop();
                if(q[top].empty()) {
                    order.pop();
                    exist[top] = false;
                }
            }
        }
    }

    return 0;
}