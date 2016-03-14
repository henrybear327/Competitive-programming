#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();
    while (cases--) {
        char inp[1000];
        fgets(inp, 1000, stdin);

        int len = strlen(inp) - 1, F = 0, M = 0;
        for (int i = 0; i < len; i++) {
            if (inp[i] == 'F')
                F++;
            else if (inp[i] == 'M')
                M++;
        }

        if (M == F && (M != 1 && F != 1))
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}
