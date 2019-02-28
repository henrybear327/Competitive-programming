#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n][n + 3];
    for(int i = 0; i < n; i++)
        scanf("%s", inp[i]);

    int ans= 0;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            if(inp[i][j] == 'X') {
                if(inp[i][j] == inp[i - 1][j - 1] &&
                   inp[i][j] == inp[i - 1][j + 1] &&
                   inp[i][j] == inp[i + 1][j - 1] &&
                   inp[i][j] == inp[i + 1][j + 1])
                    ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
