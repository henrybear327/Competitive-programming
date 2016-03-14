#include <cstdio>
#include <cstdlib>

int main()
{
    int cnt;
    while (scanf("%d", &cnt) == 1) {
        int book[10000] = {0};

        int inp[cnt];
        for (int i = 0; i < cnt; i++)
            scanf("%d", &inp[i]);

        for (int i = 1; i < cnt; i++) {
            int tmp = abs(inp[i] - inp[i - 1]);
            book[tmp]++;
        }

        bool flag = true;
        for (int i = 1; i < cnt; i++) {
            if (book[i] != 1) {
                flag = false;
                break;
            }
        }

        printf("%s\n", flag ? "Jolly" : "Not jolly");
    }

    return 0;
}
