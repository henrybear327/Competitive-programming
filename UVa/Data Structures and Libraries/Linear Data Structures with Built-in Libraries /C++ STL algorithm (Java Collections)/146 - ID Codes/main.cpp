#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char input[100];
    while (fgets(input, 100, stdin) != NULL && input[0] != '#') {
        if (next_permutation(input, input + strlen(input) - 1))
            printf("%s", input);
        else
            printf("No Successor\n");
    }

    return 0;
}
