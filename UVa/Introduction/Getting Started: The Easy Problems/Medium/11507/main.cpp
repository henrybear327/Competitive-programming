#include <cstdio>
#include <cstring>

const int turn[6][4] = {{2, 3, 4, 5},
    {3, 2, 5, 4},
    {1, 0, 2, 2},
    {0, 1, 3, 3},
    {4, 4, 1, 0},
    {5, 5, 0, 1}
};

int main()
{
    int L;
    while (scanf("%d", &L) == 1 && L != 0) {
        L--;
        int curr = 0;
        while (L--) {
            char inp[10];
            scanf("%s", inp);

            if (strcmp(inp, "+y") == 0)
                curr = turn[curr][0];
            else if (strcmp(inp, "-y") == 0)
                curr = turn[curr][1];
            else if (strcmp(inp, "+z") == 0)
                curr = turn[curr][2];
            else if (strcmp(inp, "-z") == 0)
                curr = turn[curr][3];
        }

        const char *ans[6] = {"+x", "-x", "+y", "-y", "+z", "-z"};

        printf("%s\n", ans[curr]);
    }

    return 0;
}
