#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    char inp[100010];
    scanf("%d %s", &n, inp);

    int len = strlen(inp);
    for (int i = 0; i < len; i++)
        printf("%c", (inp[i] - 'A' + n) % 26 + 'A');
    printf("\n");

    return 0;
}
