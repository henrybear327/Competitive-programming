#include <cstdio>
#include <cstring>

using namespace std;
char input[102400] = {'0'};

int main()
{
    scanf("%s", input + 1);
    int len = strlen(input);
    int last_two_digits;
    sscanf(input + len - 2, "%d", &last_two_digits);
    printf("%d\n", (last_two_digits & 3) ? 0 : 4);
    return 0;
}