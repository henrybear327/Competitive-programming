#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const char *to_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *to_lower = "abcdefghijklmnopqrstuvwxyz";
const char *to_next_num = "1234567890";

int main()
{
    char inp[10000];
    while (fgets(inp, 10000, stdin) != NULL) {
        int len = strlen(inp);
        for (int i = 0; i < len; i++) {
            if ('A' <= inp[i] && inp[i] <= 'Z')
                printf("%c", to_lower[25 - inp[i] + 'A']);
            else if ('a' <= inp[i] && inp[i] <= 'z')
                printf("%c", to_upper[25 - inp[i] + 'a']);
            else if ('0' <= inp[i] && inp[i] <= '9')
                printf("%c", to_next_num[inp[i] - '0']);
            else
                printf("%c", inp[i]);
        }
    }
    return 0;
}
