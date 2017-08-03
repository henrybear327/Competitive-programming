#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 0x3f3f3f3f;
int main()
{
    int n;
    scanf("%d", &n);
    
    int g[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = MAX;
    
    for(int i = 1; i < n; i++) {
        char inp[10000];
        for(int j = 0; j < i; j++) {
            scanf("%s", inp);
            
            if(inp[0] == 'x')
                g[i][j] = g[j][i] = MAX;
            else {
                int tmp;
                sscanf(inp, "%d", &tmp);
                g[i][j] = g[j][i] = tmp;
            }
        }
    }
    
    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < n; j++)
    //         printf("%10d%c", g[i][j], j == n - 1 ? '\n' : ' ');
    
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < n; j++)
    //         printf("%10d%c", g[i][j], j == n - 1 ? '\n' : ' ');
    
    int mx = 0;
    for(int i = 1; i < n; i++)
        mx = max(mx, g[0][i]);
    printf("%d\n", mx);
                
    
    return 0;
}