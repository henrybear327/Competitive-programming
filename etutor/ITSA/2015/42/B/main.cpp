#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);

    char input[10000];
    fgets(input, 10000, stdin);
    while (cases--) {
        fgets(input, 10000, stdin);

        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        int len = strlen(input) - 1;
        for (int i = len; i >= 0; i--) {
            if ('a' <= input[i] && input[i] <= 'z')
                printf("%c", input[i] - 'a' + 'A');
            else if ('A' <= input[i] && input[i] <= 'Z')
                printf("%c", input[i] - 'A' + 'a');
            else if ('0' <= input[i] && input[i] <= '9')
                printf("%c", input[i]);
        }
        printf("\n");
    }

    return 0;
}
