#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

typedef long long int ll;

ll solve(char *tok)
{
    if (tok[0] == 'f') {
        tok = strtok(NULL, " ");
        int x = solve(tok);

        return 2 * x - 1;
    } else if (tok[0] == 'g') {
        tok = strtok(NULL, " ");
        int x = solve(tok);
        tok = strtok(NULL, " ");
        int y = solve(tok);

        return x + 2 * y - 3;
    } else {
        return atoi(tok);
    }
}

int main()
{
    char inp[1111];
    fgets(inp, 1111, stdin);

    char *tok = strtok(inp, " ");
    printf("%lld\n", solve(tok));

    return 0;
}
