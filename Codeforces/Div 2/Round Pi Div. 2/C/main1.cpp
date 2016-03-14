#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

using namespace std;

typedef struct data {
    int number;
    int count;
} Data;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    Data input[n];
    int array[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    qsort(array, n, sizeof(int), cmp);

    int prev_index = 0, interval = 0, data_index = 0;
    for (int i = 1; i <= n; i++) {
        if (array[i] != array[prev_index]) {
            interval = i - prev_index;
            input[data_index].number = array[prev_index];
            input[data_index++].count = interval;
            prev_index = i;
            // printf("%d %d\n", data_index, prev_index);
        }
    }

    int answer = 0;

    for (int i = 0; i < data_index; i++) {
        int double_num = input[i].number * k;
        int triple_num = input[i].number * k * k;
        // printf("%d %d\n", double_num, triple_num);
        for (int j = i; j < data_index; j++) {
            if (double_num == input[j].number) {
                for (int k = j; k < data_index; k++) {
                    if (triple_num == input[k].number) {
                        if (i == j && j == k)
                            answer += 1;
                        else
                            answer += (input[i].count * input[j].count * input[k].count);
                    }
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
