#include <cstdio>
#include <cstring>

typedef struct neighbor {
    int prev, next;
} Neighbor;

int main()
{
    int soilder, query;
    while (scanf("%d %d", &soilder, &query) == 2 && (soilder || query)) {
        Neighbor data[soilder + 10];
        for (int i = 1; i <= soilder; i++) {
            data[i].prev = i - 1 >= 1 ? i - 1 : -1;
            data[i].next = i + 1 <= soilder ? i + 1 : -1;
        }

        while (query--) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (data[a].prev == -1)
                printf("* ");
            else
                printf("%d ", data[a].prev);

            if (data[b].next == -1)
                printf("*\n");
            else
                printf("%d\n", data[b].next);

            for (int i = a; i <= b; i++) {
                data[i].prev = data[a].prev;
                data[i].next = data[b].next;
            }

            data[data[a].prev].next = data[b].next;
            data[data[b].next].prev = data[a].prev; // may overflow
        }
        printf("-\n");
    }

    return 0;
}
