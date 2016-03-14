#include <cstdio>

const char *upper = {"NOPQRSTUVWXYZABCDEFGHIJKLM"};
const char *lower = {"nopqrstuvwxyzabcdefghijklm"};

int main()
{
    char input[1010];
    fgets(input, 1010, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if ('a' <= input[i] && input[i] <= 'z')
            printf("%c", lower[input[i] - 'a']);
        else if ('A' <= input[i] && input[i] <= 'Z')
            printf("%c", upper[input[i] - 'A']);
        else
            printf("%c", input[i]);
    }

    return 0;
}
