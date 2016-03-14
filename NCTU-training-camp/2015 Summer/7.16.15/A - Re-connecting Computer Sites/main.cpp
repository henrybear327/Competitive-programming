#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <climits>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct connection {
    int start, end;
    int cost;
} Connection;

Connection data[1000001];
int group[1000001];

int cmp(const void *a, const void *b)
{
    return ((Connection *)a)->cost - ((Connection *)b)->cost;
}

int find(int x)
{
    // printf("find x = %d\n", x);
    if (x == group[x])
        return x;
    return group[x] = find(group[x]); // find!!! Don't send the wrong thing!
}

int unionxy(int x, int y)
{
    // printf("%d %d\n", x, y);
    if (find(x) == find(y))
        return 0;
    group[find(x)] = find(y);
    group[x] = find(x);
    return 1;
}

int main()
{
    while (1) {
        memset(data, 0, sizeof(data));
        int computer_sites;
        scanf("%d", &computer_sites);
        computer_sites--;
        int old_cost = 0;
        for (int i = 0; i < computer_sites; i++) {
            scanf("%d %d %d", &data[i].start, &data[i].end, &data[i].cost);
            old_cost += data[i].cost;
        }
        printf("%d\n", old_cost);

        int new_cord;
        scanf("%d", &new_cord);
        for (int i = 0; i < new_cord; i++)
            scanf("%d %d %d", &data[i + computer_sites].start,
                  &data[i + computer_sites].end, &data[i + computer_sites].cost);

        int old_left;
        scanf("%d", &old_left);
        for (int i = 0; i < old_left; i++)
            scanf("%d %d %d", &data[i + computer_sites + new_cord].start,
                  &data[i + computer_sites + new_cord].end,
                  &data[i + computer_sites + new_cord].cost);

        qsort(data, computer_sites + new_cord + old_left, sizeof(Connection), cmp);

        for (int i = 0; i <= computer_sites + new_cord + old_left; i++) {
            group[i] = i;
            // printf("%d ", group[i]);
        }
        // printf("\n");

        old_cost = 0;
        for (int i = 0; i < computer_sites + new_cord + old_left; i++) {
            // printf("%d %d %d\n", data[i].start, data[i].end, data[i].cost);

            if (unionxy(data[i].start, data[i].end) == true) {
                old_cost += data[i].cost;
            }
        }
        printf("%d\n", old_cost);

        char get_newline[100];
        fgets(get_newline, 100, stdin); // get rid of scanf \n
        if (fgets(get_newline, 100, stdin) == NULL)
            break; // end of file
        else {
            printf("\n");
            continue;
        }
    }

    return 0;
}
