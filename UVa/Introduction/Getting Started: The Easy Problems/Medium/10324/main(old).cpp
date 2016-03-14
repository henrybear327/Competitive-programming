#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
    char input[1000100];
    int index = 1;
    while (fgets(input, 1000100, stdin) != NULL && input[0] != '\n') {
        printf("Case %d:\n", index++);

        int query;
        scanf("%d", &query);

        while (query--) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            char kind = input[a];
            bool flag = true;
            for (int i = a + 1; i <= b; i++) {
                if (kind != input[i]) {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }

            if (flag)
                printf("Yes\n");
        }

        getchar();
    }

    return 0;
}
