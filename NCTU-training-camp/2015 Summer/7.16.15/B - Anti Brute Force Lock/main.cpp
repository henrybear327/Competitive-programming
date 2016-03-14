#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX
#include <cmath>

using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct node {
    int number[4];
} Node;

int calculate_roll(Node a, Node b)
{
    int roll = 0;
    for (int i = 0; i < 4; i++) {
        int temp = abs(a.number[i] - b.number[i]);
        if (temp > 5)
            temp = 10 - temp;
        roll += temp;
    }
    // printf("roll %d\n", roll);
    return roll;
}

int group[510];
void init()
{
    for (int i = 0; i < 510; i++)
        group[i] = i;
    return;
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
    int test_cases;
    scanf("%d", &test_cases);
    char space[10];
    fgets(space, 10, stdin);
    while (test_cases--) {
        char input[10000];
        memset(input, 0, sizeof(input));
        fgets(input, 10000, stdin);

        char *cases_string = strtok(input, " ");
        int cases = atoi(cases_string);

        Node data[cases + 1];
        memset(data, 0, sizeof(data));
        int i = 1;
        while (i <= cases) {
            char *number = strtok(NULL, " \n");
            for (int j = 0; j < 4; j++)
                data[i].number[j] = number[j] - '0';
            i++;
        }

        // crucial!!!!
        int DP_roll[cases + 1][cases + 1];
        memset(DP_roll, 0, sizeof(DP_roll));
        for (int i = 0; i <= cases; i++) {
            for (int j = 0; j < cases; j++) {
                DP_roll[i][j] = DP_roll[j][i] = calculate_roll(data[i], data[j]);
            }
        }

        init();
        // user Prim, can't reset to 0000!!! It's starting point, not a password!
        int ans = 0, count = 0;
        while (count != cases) {
            int min = INT_MAX, min_i;
            for (int i = (count == 0 ? 0 : 1); i <= cases; i++) {
                if (group[i] == 0) {
                    for (int j = 0; j <= cases; j++) {
                        // printf("1c %d %d %d %d\n", i, j, min, min_i);
                        if (group[j] != 0 && min > MIN(DP_roll[i][j], min)) {
                            min = MIN(DP_roll[i][j], min);
                            min_i = j;
                            // printf("2c %d %d %d %d\n", i, j, min, min_i);
                        }
                    }
                }
            }
            // printf("out%d %d\n", min, min_i);
            unionxy(min_i, 0);
            count++;
            ans += min;
            // printf("count %d ==>", count);
            // for (int i = 0; i <= cases; i++)
            // printf("%d ", group[i]);
            // printf("\n");
        }
        printf("%d\n", ans);
    }

    return 0;
}
