#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
    char input[1000100];
    int index = 1;
    while (fgets(input, 1000100, stdin) != NULL && input[0] != '\n') {
        printf("Case %d:\n", index++);

        int len = strlen(input) - 1;
        int group[len];
        memset(group, 0, sizeof(group));

        int counter = 0;
        char prev = input[0];
        for (int i = 0; i < len; i++) {
            if (input[i] == prev) {
                group[i] = counter;
            } else {
                prev = input[i];
                group[i] = ++counter;
            }
        }

        int query;
        scanf("%d", &query);

        while (query--) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (group[a] == group[b])
                printf("Yes\n");
            else
                printf("No\n");
        }

        getchar();
    }

    return 0;
}
