#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int k;
        scanf("%d", &k);

        int pay[260] = {0};
        for (int i = 0; i < k; i++) {
            char c[10];
            int cost;
            scanf("%s %d", c, &cost);

            pay[(int)c[0] + 128] = cost;
        }

        int lines;
        scanf("%d", &lines);

        char inp[20000];
        fgets(inp, 20000, stdin); // get dangling \n

        double ans = 0;
        while (lines--) {
            fgets(inp, 20000, stdin); // get dangling \n

            int len = strlen(inp) - 1;
            for (int i = 0; i < len; i++)
                ans += (pay[(int)inp[i] + 128]);
        }

        printf("%.2f$\n", ans / 100);
    }

    return 0;
}
