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

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int num_block;
        scanf("%d", &num_block);

        char input[1000];
        fgets(input, 1000, stdin);
        fgets(input, 1000, stdin);
        // printf("input %s", input);
        int data[1000];
        memset(data, 0, sizeof(data));
        int len = strlen(input);
        for (int i = 0; i < len; i++) {
            if (input[i] == '.') {
                data[i] = 0;
            } else if (input[i] == '*') {
                data[i] = 1;
            }
        }

        // for (int i = 0; i <= num_block; i++)
        // printf("%d", data[i]);
        // printf("\n");

        for (int i = 0; i < num_block; i++) {
            if (data[i] == 1) {
                if (data[i + 1] == 1) {
                    data[i - 1] = 1;
                } else {
                    data[i + 1] = data[i - 1] = 1;
                    i++;
                }
            }
        }

        // for (int i = 0; i < num_block; i++)
        // printf("%d", data[i]);
        // printf("\n");

        int count = 0;
        for (int i = 0; i < num_block; i++) {
            if (i == 0 && data[i] == 0) {
                data[i] = data[i + 1] = data[i + 2] = 1;
                count++;
            } else if (i == num_block - 1 && data[i] == 0) {
                data[i] = 1;
                count++;
            } else if (data[i] == 0) {
                data[i] = data[i + 1] = data[i + 2] = 1;
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}