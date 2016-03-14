#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

typedef struct line {
    int L;
    int R;
    bool used;
} Line;

int cmp(const void *a, const void *b)
{
    if (((Line *)a)->L == ((Line *)b)->L)
        return ((Line *)b)->R - ((Line *)a)->R; // descending order
    else
        return ((Line *)a)->L - ((Line *)b)->L; // ascending order
}

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) == 1) {
        bool first = false;
        while (test_cases--) {
            if (first)
                printf("\n");
            else
                first = true;
            int ending;
            char input[100];
            while (fgets(input, 100, stdin) != NULL) {
                if (input[0] == '\n' || input[0] == '\r')
                    continue;
                ending = atoi(input);
                break;
            }

            Line data[100000];
            memset(data, 0, sizeof(data));
            int i = 0;
            while (1) {
                scanf("%d %d", &data[i].L, &data[i].R);
                if (data[i].L > data[i].R) {
                    int temp = data[i].L;
                    data[i].L = data[i].R;
                    data[i].R = temp;
                }
                if (data[i].L == 0 && data[i].R == 0)
                    break;
                i++;
            }

            qsort(data, i, sizeof(Line), cmp);
            // printf("Start...!\n");

            int ending_so_far = 0, count = 1, temp_j;
            for (int j = 0; j < i; j++) {
                if (data[j].L <= 0 && data[j].R >= 0 && data[j].R > ending_so_far) {
                    ending_so_far = data[j].R;
                    data[j].used = true;
                    temp_j = j;
                }
            }
            if (ending_so_far >= ending) {
                printf("%d\n", count);
                printf("%d %d\n", data[temp_j].L, data[temp_j].R);
                continue;
            }
            if (ending_so_far == 0) {
                printf("0\n");
                continue;
            }

            while (ending_so_far < ending) {
                for (int j = 0; j < i; j++) {
                    if (data[j].L > data[temp_j].L && data[j].L <= data[temp_j].R &&
                        data[j].R > data[temp_j].L) {
                        temp_j = j;
                    }
                }
                count++;
                ending_so_far = data[temp_j].R;
                data[temp_j].used = true;
            }

            printf("%d\n", count);
            for (int j = 0; j < i; j++) {
                if (data[j].used)
                    printf("%d %d\n", data[j].L, data[j].R);
            }
        }
    }
    return 0;
}
