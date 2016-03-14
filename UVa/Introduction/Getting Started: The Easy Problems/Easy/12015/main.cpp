#include <cstdio>

typedef struct data {
    char url[200];
    int rank;
} Data;

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();

    Data info[10];
    int index = 1;
    while (cases--) {
        int max = -1;
        for (int i = 0; i < 10; i++) {
            char input[1000];
            fgets(input, 1000, stdin);

            sscanf(input, "%s %d", info[i].url, &info[i].rank);

            if (info[i].rank > max)
                max = info[i].rank;
        }

        printf("Case #%d:\n", index++);
        for (int i = 0; i < 10; i++)
            if (max == info[i].rank)
                printf("%s\n", info[i].url);
    }

    return 0;
}
