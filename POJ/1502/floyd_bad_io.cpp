#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 0x3f3f3f3f;
int main()
{
    int n;
    char inp[10000];
    fgets(inp, 10000, stdin);
    sscanf(inp, "%d", &n);
    
    int g[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = MAX;
    
    for(int i = 1; i < n; i++) {
        int j = 0;
        fgets(inp, 10000, stdin);
        char *tok = strtok(inp, " ");
        
        while(tok != NULL) {
            if(tok[0] == 'x')
                g[i][j] = g[j][i] = MAX;
            else
                g[i][j] = g[j][i] = atoi(tok);
            
            tok = strtok(NULL, " ");
            j++;
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