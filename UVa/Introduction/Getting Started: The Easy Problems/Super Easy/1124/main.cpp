#include <cstdio>

int main()
{
    char input[1000];
    while (fgets(input, 1000, stdin) != NULL)
        printf("%s", input);

    return 0;
}
