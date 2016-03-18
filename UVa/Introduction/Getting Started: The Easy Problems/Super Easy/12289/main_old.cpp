#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    char buffer[10];
    fgets(buffer, 10, stdin);

    while (cases--) {
        char input[10];
        fgets(input, 10, stdin);

        int len = strlen(input) - 1;
        if (len == 5)
            printf("3\n");
        else {
            char one[4] = "one";
            int count = 0;
            for (int i = 0; i < 3; i++) {
                if (input[i] == one[i])
                    count++;
            }
            if (count >= 2)
                printf("1\n");
            else
                printf("2\n");
        }
    }

    return 0;
}
