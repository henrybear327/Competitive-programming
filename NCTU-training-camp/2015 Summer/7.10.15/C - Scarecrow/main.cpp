#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) == 1) {
        getchar();
        int counter = 1;
        while (test_cases--) {
            int len;
            scanf("%d", &len);
            getchar();
            char input[len + 10];
            memset(input, 0, sizeof(input));
            fgets(input, len + 10, stdin);
            // printf("%s", input);

            int count = 0;
            for (int i = 0; i < len; i++) {
                if (input[i] == '.') {
                    input[i] = input[i + 1] = input[i + 2] = '#';
                    count++;
                } else if (input[i] == '#') {
                    continue;
                }
            }

            printf("Case %d: %d\n", counter++, count);
        }
    }

    return 0;
}