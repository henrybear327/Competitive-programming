#include <cstdio>
#include <cstring>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char inp[100000];
    fgets(inp, 100000, stdin);
    int b = 0, g = 0;
    for (int i = 0; i < n; i++) {
        fgets(inp, 100000, stdin);
        int len = strlen(inp) - 1;
        for (int j = 0; j < len; j++) {
            if (inp[j] - '0' == 0)
                g++;
            else if (inp[j] - '0' == 1)
                b++;
        }
    }

    printf("%d\n", g > b ? 0 : g == b ? 2 : 1);

    return 0;
}
