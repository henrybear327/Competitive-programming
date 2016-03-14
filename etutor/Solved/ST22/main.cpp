#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        char inp1[100], inp2[100];
        scanf("%s %s", inp1, inp2);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < (int)strlen(inp1); i++) {
            num1 <<= 1;
            num1 += inp1[i] - '0';
        }

        for (int i = 0; i < (int)strlen(inp2); i++) {
            num2 <<= 1;
            num2 += inp2[i] - '0';
        }
        printf("%d\n", num1 + num2);
    }
    return 0;
}
