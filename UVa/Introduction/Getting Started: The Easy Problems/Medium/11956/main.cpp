#include <cstdio>
#include <cstring>

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();

    int index = 1;
    while (cases--) {
        char input[100010];
        fgets(input, 100010, stdin);

        int len = strlen(input) - 1;
        unsigned char data[100] = {0};
        int pointer = 0;
        for (int i = 0; i < len; i++) {
            if (input[i] == '+')
                data[pointer] = data[pointer] == 255 ? 0 : data[pointer] + 1;
            else if (input[i] == '-')
                data[pointer] = data[pointer] == 0 ? 255 : data[pointer] - 1;
            else if (input[i] == '>')
                pointer = pointer == 99 ? 0 : pointer + 1;
            else if (input[i] == '<')
                pointer = pointer == 0 ? 99 : pointer - 1;
        }

        printf("Case %d: ", index++);
        for (int i = 0; i < 100; i++) {
            if (i != 99)
                printf("%02X ", data[i]);
            else
                printf("%02X\n", data[i]);
        }
    }

    return 0;
}
