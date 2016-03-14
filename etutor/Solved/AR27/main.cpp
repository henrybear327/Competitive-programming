#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int n;
    char input[70000 * 6];
    while (fgets(input, 70000 * 6, stdin) != NULL) {
        sscanf(input, "%d", &n);
        int cnt = 0;
        fgets(input, 70000 * 6, stdin);
        int book[70010] = {0};

        char *token = strtok(input, " \n");
        while (token != NULL) {
            book[atoi(token)] = 1;
            cnt++;
            token = strtok(NULL, " \n");
        }

        cnt = n - cnt;
        for (int i = 1; i <= n; i++)
            if (book[i] == 0) {
                printf("%d%c", i, cnt == 1 ? '\n' : ' ');
                cnt--;
            }
    }
    return 0;
}
