#include <cstdio>
#include <cstring>

int main()
{
    char input[1000010];
    while (fgets(input, 1000010, stdin) != NULL && input[0] != 'E') {
        if (strlen(input) - 1 == 1 && input[0] == '1') {
            printf("1\n");
            continue;
        }

        int curr = strlen(input) - 1, ans = 1;
        while (1) {
            int len = 0, tmp = curr;
            while (curr) {
                curr /= 10;
                len++;
            }

            if (tmp != len) {
                curr = len;
                ans++;
            } else {
                printf("%d\n", ++ans);
                break;
            }
        }
    }

    return 0;
}
