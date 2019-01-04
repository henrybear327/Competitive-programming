#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int cmd, depth;
    scanf("%d %d", &cmd, &depth);
    getchar();

    int buy[100010], sold[100010];
    memset(buy, 0, sizeof(buy));
    memset(sold, 0, sizeof(sold));

    for (int i = 1; i <= cmd; i++) {
        char inp[1000];
        fgets(inp, 1000, stdin);

        char c;
        int p, q;
        sscanf(inp, "%c %d %d", &c, &p, &q);

        if (c == 'B') {
            buy[p] += q;
        } else {
            sold[p] += q;
        }
    }

    int count = 0, max;
    for (int j = 0; count < depth && j < 100010; j++) {
        if (sold[j] > 0) {
            count++;
            max = j;
        }
    }

    for (int i = max; i >= 0; i--)
        if (sold[i] > 0)
            printf("S %d %d\n", i, sold[i]);

    count = 0;
    for (int j = 100009; count < depth && j >= 0; j--) {
        if (buy[j] > 0) {
            printf("B %d %d\n", j, buy[j]);
            count++;
        }
    }

    return 0;
}
