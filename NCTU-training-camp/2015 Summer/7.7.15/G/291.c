#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int map[5][5] = {{0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0}
};

struct data {
    int temp[5][5];
};

int ans[9];

void dfs(int level, struct data temp, int prev)
{
    if (level == 8) {
        // print sequence
        for (int i = 0; i < 8; i++)
            printf("%d", ans[i] + 1);
        printf("2\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (temp.temp[prev][i] == 1) {
            temp.temp[prev][i] = 0;
            temp.temp[i][prev] = 0;
            ans[level + 1] = i;
            dfs(level + 1, temp, i);
            temp.temp[prev][i] = 1;
            temp.temp[i][prev] = 1;
        }
    }

    return;
}

int main()
{
    struct data temp = {{{0, 1, 1, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {1, 1, 1, 1, 0}
        }
    };
    memset(ans, 0, sizeof(ans));
    ans[0] = 0;
    dfs(0, temp, 0);
    return 0;
}
